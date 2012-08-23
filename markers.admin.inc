<?php
//$Id$

function markers_setting(){
  $form = array();

  $form['skmap_markers'] = array(
    '#type' => 'fieldset',
    '#title' => t('Markers configurations'),
    '#descriptions' => t('Manage and configure markers for ShakeMap.'),
  );

  $form['skmap_markers']['image_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Base path to the markers icons'),
    '#description' => t('The base path where the icons images is stored, relative to the Drupal base path.'),
    '#default_value' => variable_get('skmap_markers_path', 'sites/default/files/skmap/markers/'),
  );

  $form['skmap_markers']['markers'] = array(
    '#type' => 'textarea',
    '#title' => t('Markers'),
    '#description' => t('Add markers to the map, in a way <em>category|url of image</em>. One per line. <strong>Remember:</strong> the marker <em>default</em> must always exist!'),
    '#default_value' => variable_get('skmap_markers_markers', "default|default.png"),
  );

  $form['#submit'][] = 'markers_setting_submit';

  return system_settings_form($form);
}

function markers_setting_submit($form, &$form_state){
  variable_set('skmap_markers_markers', $form_state['values']['markers']);
  variable_set('skmap_markers_path', $form_state['values']['image_path']);
}

?>