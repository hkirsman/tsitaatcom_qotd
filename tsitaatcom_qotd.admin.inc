<?php

/**
 * @file
 * Includes the admin interface for 'tsitaatcom quote of the day' module.
 */

/**
 * Menu callback: tsitaatcom module settings form.
 */
function tsitaatcom_qotd_settings_form($form, &$form_state) {
  $form['tsitaatcom_qotd'] = array(
    '#type' => 'textfield',
    '#title' => t("I don't know what this will be."),
    '#default_value' => variable_get('tsitaatcom_quotes_on_page'),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('If there are more quotes than the value defined here a pager is shown.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
