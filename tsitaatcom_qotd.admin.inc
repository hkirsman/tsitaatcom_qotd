<?php

/**
 * @file
 * Includes the admin interface for 'tsitaatcom quote of the day' module.
 */

/**
 * Menu callback: tsitaatcom module settings form.
 */
function tsitaatcom_qotd_settings_form($form, &$form_state) {
  $form['tsitaatcom_qotd_fb'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['tsitaatcom_qotd_fb']['tsitaatcom_qotd_fb_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is posting to Facebook enabled?'),
    '#default_value' => variable_get('tsitaatcom_qotd_fb_enabled'),
  );

  $form['tsitaatcom_qotd_fb']['tsitaatcom_qotd_fb_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('App id'),
    '#default_value' => variable_get('tsitaatcom_qotd_fb_app_id'),
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => variable_get('tsitaatcom_qotd_fb_enabled', 0) === 0 ? FALSE : TRUE,
  );

  $form['tsitaatcom_qotd_fb']['tsitaatcom_qotd_fb_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret'),
    '#default_value' => variable_get('tsitaatcom_qotd_fb_secret'),
    '#size' => 40,
    '#maxlength' => 50,
    '#required' => variable_get('tsitaatcom_qotd_fb_enabled', 0) === 0 ? FALSE : TRUE,
  );

  $form['tsitaatcom_qotd_fb']['tsitaatcom_qotd_fb_token'] = array(
    '#type' => 'textarea',
    '#title' => t('Token'),
    '#default_value' => variable_get('tsitaatcom_qotd_fb_token'),
    '#required' => variable_get('tsitaatcom_qotd_fb_enabled', 0) === 0 ? FALSE : TRUE,
  );

  $form['tsitaatcom_qotd_fb']['tsitaatcom_qotd_fb_wall'] = array(
    '#type' => 'textfield',
    '#title' => t('Wall'),
    '#default_value' => variable_get('tsitaatcom_qotd_fb_wall'),
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => variable_get('tsitaatcom_qotd_fb_enabled', 0) === 0 ? FALSE : TRUE,
  );

  // Add FB Wall link if the id is set.
  if (strlen(variable_get('tsitaatcom_qotd_fb_wall', '')) > 0) {
    $fb_wall_link_options = array(
      'attributes' => array(
        'class' => 'tsitaatcom-qotd-fb-wall-link',
        'target' => '_blank',
      ),
    );
    $fb_wall_link = l(t('Link to wall'), 'https://www.facebook.com/243092539190637', $fb_wall_link_options);
    $form['tsitaatcom_qotd_fb']['tsitaatcom_qotd_fb_wall']['#suffix'] = $fb_wall_link;
    drupal_add_css('.form-item-tsitaatcom-qotd-fb-wall {float: left} .form-item {clear: left}', array('type' => 'inline'));
    drupal_add_css('.tsitaatcom-qotd-fb-wall-link {margin: 28px 0px 0px 10px; display: inline-block;} ', array('type' => 'inline'));
  }

  $form['tsitaatcom_qotd_twitter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['tsitaatcom_qotd_twitter']['tsitaatcom_qotd_twitter_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Is posting to Twitter enabled?'),
    '#default_value' => variable_get('tsitaatcom_qotd_twitter_enabled', 0),
  );

  $form['tsitaatcom_qotd_twitter']['tsitaatcom_qotd_twitter_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('tsitaatcom_qotd_twitter_username'),
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => FALSE,
  );

  // Add FB Wall link if the id is set.
  if (strlen(variable_get('tsitaatcom_qotd_twitter_username', '')) > 0) {
    $twitter_link_options = array(
      'attributes' => array(
        'class' => 'tsitaatcom-qotd-twitter-link',
        'target' => '_blank',
      ),
    );
    $twitter_link = l(t('Link to twitter'), 'https://twitter.com/' . variable_get('tsitaatcom_qotd_twitter_username'), $twitter_link_options);
    $form['tsitaatcom_qotd_twitter']['tsitaatcom_qotd_twitter_username']['#suffix'] = $twitter_link;
    drupal_add_css('.form-item-tsitaatcom-qotd-twitter-username {float: left;} .form-item {clear: left}', array('type' => 'inline'));
    drupal_add_css('.tsitaatcom-qotd-twitter-link {margin: 28px 0px 0px 10px; display: inline-block;} ', array('type' => 'inline'));
  }

  $form['tsitaatcom_qotd_twitter']['tsitaatcom_qotd_twitter_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer Key (API Key)'),
    '#default_value' => variable_get('tsitaatcom_qotd_twitter_consumer_key'),
    '#size' => 30,
    '#maxlength' => 40,
    '#required' => variable_get('tsitaatcom_qotd_twitter_enabled', 0) === 0 ? FALSE : TRUE,
  );

  $form['tsitaatcom_qotd_twitter']['tsitaatcom_qotd_twitter_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer Secret (API Secret)'),
    '#default_value' => variable_get('tsitaatcom_qotd_twitter_consumer_secret'),
    '#size' => 70,
    '#maxlength' => 100,
    '#required' => variable_get('tsitaatcom_qotd_twitter_enabled', 0) === 0 ? FALSE : TRUE,
  );

  $form['tsitaatcom_qotd_twitter']['tsitaatcom_qotd_twitter_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Access Token'),
    '#default_value' => variable_get('tsitaatcom_qotd_twitter_access_token'),
    '#size' => 60,
    '#maxlength' => 100,
    '#required' => variable_get('tsitaatcom_qotd_twitter_enabled', 0) === 0 ? FALSE : TRUE,
  );

  $form['tsitaatcom_qotd_twitter']['tsitaatcom_qotd_twitter_access_token_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Access Token Secret'),
    '#default_value' => variable_get('tsitaatcom_qotd_twitter_access_token_secret'),
    '#size' => 60,
    '#maxlength' => 100,
    '#required' => variable_get('tsitaatcom_qotd_twitter_enabled', 0) === 0 ? FALSE : TRUE,
  );

  return system_settings_form($form);
}
