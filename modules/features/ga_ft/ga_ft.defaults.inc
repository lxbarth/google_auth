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
  $feeds_importer->id = 'street_segments';
  $feeds_importer->config = array(
    'name' => 'Street segments',
    'description' => 'Upload street segments',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
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
            'source' => 'votebuilder id',
            'target' => 'votebuilder_id',
            'unique' => FALSE,
          ),
          '1' => array(
            'source' => 'streetno',
            'target' => 'streetno',
            'unique' => FALSE,
          ),
          '2' => array(
            'source' => 'streetnohalf',
            'target' => 'streetnohalf',
            'unique' => FALSE,
          ),
          '3' => array(
            'source' => 'streetprefix',
            'target' => 'streetprefix',
            'unique' => FALSE,
          ),
          '4' => array(
            'source' => 'streetname',
            'target' => 'streetname',
            'unique' => FALSE,
          ),
          '5' => array(
            'source' => 'streettype',
            'target' => 'streettype',
            'unique' => FALSE,
          ),
          '6' => array(
            'source' => 'streetsuffix',
            'target' => 'streetsuffix',
            'unique' => FALSE,
          ),
          '7' => array(
            'source' => 'apttype',
            'target' => 'apttype',
            'unique' => FALSE,
          ),
          '8' => array(
            'source' => 'aptno',
            'target' => 'aptno',
            'unique' => FALSE,
          ),
          '9' => array(
            'source' => 'city',
            'target' => 'city',
            'unique' => FALSE,
          ),
          '10' => array(
            'source' => 'state',
            'target' => 'state',
            'unique' => FALSE,
          ),
          '11' => array(
            'source' => 'zip5',
            'target' => 'zip5',
            'unique' => FALSE,
          ),
          '12' => array(
            'source' => 'zip4',
            'target' => 'zip4',
            'unique' => FALSE,
          ),
          '13' => array(
            'source' => 'vaddress',
            'target' => 'vaddress',
            'unique' => FALSE,
          ),
          '14' => array(
            'source' => 'maddress',
            'target' => 'maddress',
            'unique' => FALSE,
          ),
          '15' => array(
            'source' => 'mcity',
            'target' => 'mcity',
            'unique' => FALSE,
          ),
          '16' => array(
            'source' => 'mstate',
            'target' => 'mstate',
            'unique' => FALSE,
          ),
          '17' => array(
            'source' => 'mzip5',
            'target' => 'mzip5',
            'unique' => FALSE,
          ),
          '18' => array(
            'source' => 'mzip4',
            'target' => 'mzip4',
            'unique' => FALSE,
          ),
          '19' => array(
            'source' => 'countyname',
            'target' => 'countyname',
            'unique' => FALSE,
          ),
          '20' => array(
            'source' => 'precinctname',
            'target' => 'precinctname',
            'unique' => FALSE,
          ),
          '21' => array(
            'source' => 'cd',
            'target' => 'cd',
            'unique' => FALSE,
          ),
          '22' => array(
            'source' => 'sd',
            'target' => 'sd',
            'unique' => FALSE,
          ),
          '23' => array(
            'source' => 'hd',
            'target' => 'hd',
            'unique' => FALSE,
          ),
          '24' => array(
            'source' => 'countycommissionercode',
            'target' => 'countycommissionercode',
            'unique' => FALSE,
          ),
          '25' => array(
            'source' => 'schoolcode',
            'target' => 'schoolcode',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => 'street_segments',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['street_segments'] = $feeds_importer;
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
  $strongarm->name = 'node_options_street_segments';
  $strongarm->value = array(
    '0' => 'status',
    '1' => 'promote',
  );

  $export['node_options_street_segments'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_street_segments';
  $strongarm->value = '1';

  $export['upload_street_segments'] = $strongarm;
  return $export;
}
