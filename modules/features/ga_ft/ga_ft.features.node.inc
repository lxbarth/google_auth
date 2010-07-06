<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _ga_ft_node_info() {
  $items = array(
    'country_listing' => array(
      'name' => t('Country listing'),
      'module' => 'features',
      'description' => t('Upload a country listing to fusion tables.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
