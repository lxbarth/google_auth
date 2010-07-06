<?php

/**
 * Upload to Google Fusion Tables.
 */
class FeedsFTProcessor extends FeedsProcessor {
  /**
   * Implementation of FeedsProcessor::process().
   */
  public function process(FeedsImportBatch $batch, FeedsSource $source) {
    while ($item = $batch->shiftItem()) {

    }
  }

  /**
   * Implementation of FeedsProcessor::clear().
   */
  public function clear(FeedsBatch $batch, FeedsSource $source) {
    throw Exception(t('Not supported'));
  }

//  /**
//   * Default configuration.
//   */
//  public function configDefaults() {
//    $defaults = parent::configDefaults();
//    $defaults['mapping_targets'] =
//    return $defaults
//  }
//
  /**
   * Handle adding a mapping.
   */
  public function addMapping($source, $target, $unique = FALSE) {
    parent::addMapping($source, $source, $unique);
  }

  /**
   * Override parent::getMappingTargets().
   */
  public function getMappingTargets() {
    return array(
      'new' => array(
        'name' => t('New'),
        'description' => t('Add a new mapping target.'),
      ),
    );
  }
}
