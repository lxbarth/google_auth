<?php

// Create FEEDS_FT_BATCH_SIZE at a time.
define('FEEDS_FT_BATCH_SIZE', 100);

/**
 * Upload to Google Fusion Tables.
 */
class FeedsFTProcessor extends FeedsProcessor {
  /**
   * Implementation of FeedsProcessor::process().
   *
   * @todo Implement batch support.
   */
  public function process(FeedsImportBatch $batch, FeedsSource $source) {
    // @todo Use feed node's owner?
    global $user;
    $fusion = gdata_fusion_user_get_client($user);
    $source_config = $source->getConfigFor($this);

    // Allocate a Fusion table if it does not exist yet.
    // @todo: modify table if mapping has changed in meantime.
    $ft_id = $source_config['fusion_table_id'];
    $schema = $this->getFTSchema();
    if (empty($ft_id)) {
      if ($ft_id = $fusion->createTable('feeds_'. $this->id .'_'. $source->feed_nid, $schema)) {
        $source_config['fusion_table_id'] = $ft_id;
        $source->addConfig(array(get_class($this) => $source_config));
      }
      else {
        throw new Exception(t('Could not create Fusion Table.'));
      }
    }

    // Iterate through all items and store to FT.
    $created = 0;
    $data = array();
    while ($item = $batch->shiftItem()) {
      $data[] = $this->map($item);
      $created++;
      $batch->created++;
      if ($created > variable_get('feeds_ft_batch_size', FEEDS_FT_BATCH_SIZE)) {
        return (1.0 / ($batch->total + 1)) * $batch->created; // @todo: move this into $batch->progress();
      }
    }

    // Set messages.
    if ($batch->created) {
      if ($fusion->insertData($ft_id, array_keys($schema), $data)) {
        drupal_set_message(t('Created !created items in Google Fusion Tables', array('!created' => $batch->created)));
      }
      else {
        drupal_set_message(t('There was an error transferring data to Google Fusion Tables'), 'error');
      }
    }
    else {
      drupal_set_message(t('There is no data to be transferred to Google Fusion Tables'));
    }

    return FEEDS_BATCH_COMPLETE;
  }

  /**
   * Implementation of FeedsProcessor::clear().
   */
  public function clear(FeedsBatch $batch, FeedsSource $source) {
    throw Exception(t('Not supported'));
  }

  /**
   * Declare source defaults.
   *
   * Declare a fusion table ID to be stored for each source.
   */
  public function sourceDefaults() {
    return array(
      'fusion_table_id' => NULL,
    );
  }

  /**
   * Declare that we have source configuration.
   *
   * @todo FeedsPlugin::hasSourceConfig() should use sourceDefaults() for
   * determining whether a plugin has source configuration or not.
   */
  public function hasSourceConfig() {
    return TRUE;
  }

  /**
   * Override parent::map().
   */
  protected function map($source_item, $target_item = NULL) {
    $parser = feeds_importer($this->id)->parser;
    if (empty($target_item)) {
      $target_item = array();
    }
    foreach ($this->config['mappings'] as $mapping) {
      $value = $parser->getSourceElement($source_item, $mapping['source']);
      $this->setTargetElement($target_item, $mapping['target'], $value);
    }
    return $target_item;
  }

  /**
   * Handle adding a mapping.
   *
   * @todo: sanitize $source names as not all characters are allowed in FT
   * tables.
   */
  public function addMapping($source, $target, $unique = FALSE) {
    parent::addMapping($source, $source, $unique);
  }

  /**
   * Override parent::getMappingTargets().
   *
   * @todo: implement types STRING, NUMBER, LOCATION, DATETIME
   */
  public function getMappingTargets() {
    return array(
      'new' => array(
        'name' => t('New'),
        'description' => t('Add a new mapping target.'),
      ),
    );
  }

  /**
   * Build a Fusion Table schema from mappings.
   */
  public function getFTSchema() {
    $schema = array();
    $mappings = $this->getMappings();
    foreach ($mappings as $mapping) {
      $schema[$mapping['target']] = 'STRING';
    }
    return $schema;
  }
}
