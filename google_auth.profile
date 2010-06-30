<?php

include_once dirname(__FILE__) .'/../buildkit/buildkit.profile';

/**
 * Return an array of the modules to be enabled when this profile is installed.
 */
function google_auth_profile_modules() {
  $modules = buildkit_profile_modules();
  $modules = array_merge($modules,
    array(
      'devel',
      'gdata',
      'oauth_common',
      'zend',
      'autoload',
      'gdata_fusion',
      'gdata_oauth',
    )
  );
  return $modules;
}

/**
 * Return a description of the profile for the initial installation screen.
 */
function google_auth_profile_details() {
  return array(
    'name' => 'Google API testing',
    'description' => 'Google Authentication/Authorization testing.'
  );
}

/**
 * Perform any final installation tasks for this profile.
 */
function google_auth_profile_tasks(&$task, $url) {
  // This is where features are usually being enabled.
  $features = array(
  );
  drupal_install_modules($features);

  // Rebuild key tables/caches.
  drupal_flush_all_caches();

  // Enabe cube as default theme.
  buildkit_enable_theme('cube', 'google_auth');
}

/**
 * Simplify installation.
 */
function google_auth_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'install_configure') {
    $form['site_information']['site_name']['#default_value'] = 'Google Auth';
    $form['site_information']['site_mail']['#default_value'] = 'admin@'. $_SERVER['HTTP_HOST'];
    $form['admin_account']['account']['name']['#default_value'] = 'admin';
    $form['admin_account']['account']['mail']['#default_value'] = 'admin@'. $_SERVER['HTTP_HOST'];
  }
}
