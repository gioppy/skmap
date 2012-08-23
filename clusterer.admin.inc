<?php
//$Id$

function clusterer_setting(){
  $form = array();

  $form['skmap_clusterer'] = array(
    '#type' => 'fieldset',
    '#title' => t('MarkerClusterer configurations'),
    '#descriptions' => t('Manage and configure MarkerClusterer library.'),
  );

  $form['skmap_clusterer']['image_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Base path to the markers icons'),
    '#description' => t('The base path where the icons images is stored, relative to the Drupal base path.'),
    '#default_value' => variable_get('skmap_clusterer_path', 'sites/default/files/skmap/clusterer/'),
  );

  $form['#submit'][] = 'clusterer_setting_submit';

  return system_settings_form($form);
}

function clusterer_setting_submit($form, &$form_state){
  variable_set('skmap_clusterer_path', $form_state['values']['image_path']);
}

?>