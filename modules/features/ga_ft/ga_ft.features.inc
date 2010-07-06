<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ga_ft_ctools_plugin_api() {
  module_load_include('inc', 'ga_ft', 'ga_ft.defaults');
  $args = func_get_args();
  return call_user_func_array('_ga_ft_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function ga_ft_feeds_importer_default() {
  module_load_include('inc', 'ga_ft', 'ga_ft.defaults');
  $args = func_get_args();
  return call_user_func_array('_ga_ft_feeds_importer_default', $args);
}

/**
 * Implementation of hook_node_info().
 */
function ga_ft_node_info() {
  module_load_include('inc', 'ga_ft', 'ga_ft.features.node');
  $args = func_get_args();
  return call_user_func_array('_ga_ft_node_info', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function ga_ft_strongarm() {
  module_load_include('inc', 'ga_ft', 'ga_ft.defaults');
  $args = func_get_args();
  return call_user_func_array('_ga_ft_strongarm', $args);
}
