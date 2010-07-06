<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _ga_ft_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _ga_ft_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'country_listing';
  $feeds_importer->config = array(
    'name' => 'Country listing',
    'description' => 'Upload a country listing.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFTProcessor',
      'config' => array(
        'mappings' => array(
          '0' => array(
            'source' => 'id',
            'target' => 'id',
            'unique' => FALSE,
          ),
          '1' => array(
            'source' => 'country_en',
            'target' => 'country_en',
            'unique' => FALSE,
          ),
          '2' => array(
            'source' => 'country_lang',
            'target' => 'country_lang',
            'unique' => FALSE,
          ),
          '3' => array(
            'source' => 'lang',
            'target' => 'lang',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => 'country_listing',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['country_listing'] = $feeds_importer;
  return $export;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _ga_ft_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_country_listing';
  $strongarm->value = array(
    '0' => 'status',
    '1' => 'promote',
  );

  $export['node_options_country_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_country_listing';
  $strongarm->value = '0';

  $export['upload_country_listing'] = $strongarm;
  return $export;
}
