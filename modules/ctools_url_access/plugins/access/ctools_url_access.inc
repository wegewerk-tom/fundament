<?php

/**
 * @file
 * Plugin to provide access control based on url.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('URL Regex'),
  'description' => t('URL matches a regular expression.'),
  'callback' => 'ctools_url_regex_access_check',
  'default' => array('value' => '/.*/'),
  'settings form' => 'ctools_url_regex_access_settings',
  'summary' => 'ctools_url_regex_access_summary',
);


/**
 * Settings form for the 'by parent term' access plugin
 */
function ctools_url_regex_access_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  $form['settings']['value'] = array(
    '#type' => 'textfield',
    '#title' => t('Regex'),
    '#default_value' => $conf['value'],
  );
  return $form;
}

/**
 * Check for access.
 */
function ctools_url_regex_access_check($conf, $context) {
  global $base_url;
  $url = $base_url . implode("/", explode("/", $_SERVER['REQUEST_URI']));
  if (preg_match($conf['value'], $url) === 1) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Provide a summary description based upon the checked terms.
 */
function ctools_url_regex_access_summary($conf, $context) {
  return t('A matching URL');
}
