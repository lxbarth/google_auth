<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _ga_ft_node_info() {
  $items = array(
    'street_segments' => array(
      'name' => t('Street segments'),
      'module' => 'features',
      'description' => '',
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
