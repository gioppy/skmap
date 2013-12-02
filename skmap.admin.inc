<?php
//$Id$

function skmap_setting(){
  $form = array();

  $form['skmap_settings'] = array(
	'#type' => 'fieldset',
	'#title' => t('SK Map settings'),
	'#description' => t('General Settings for SK Map.'),
  );

  $node_types = node_type_get_names();
  $form['skmap_settings']['node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Contet type to use Google Maps'),
    '#options' => $node_types,
	'#default_value' => variable_get('skmap_settings_node_types', array()),
  );

  $form['skmap_settings']['other_page'] = array(
    '#type' => 'textarea',
    '#title' => t('Extra page to use Google Maps'),
    '#description' => t('Add extra page path to use Google Map.'),
    '#default_value' => variable_get('skmap_settings_other_page', ""),
  );

  $form['skmap_libraries'] = array(
    '#type' => 'fieldset',
    '#title' => t('Libraries and plug-ins'),
    '#description' => t('Libraries and plug-ins settings,'),
  );

  $form['skmap_libraries']['use_infobox'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Infobox library'),
    '#default_value' => variable_get('skmap_libraries_infobox', 0),
  );

  $form['skmap_libraries']['use_oms'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use OverlappingMarkerSpiderfier library'),
    '#default_value' => variable_get('skmap_libraries_oms', 0),
  );

  $form['skmap_libraries']['shakemap_js'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use minified version of ShakeMap.js'),
    '#default_value' => variable_get('skmap_libraries_shakemap_min', 0),
  );

  $form['skmap_gmap'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google Maps Settings'),
    '#description' => t('General settings of Google Maps'),
  );

  $form['skmap_gmap']['map_options'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Map Options'),
    '#options' => array(
      'mapTypeControl' => t('Enabled/disabled <strong>Map type control</strong>.'),
      'panControl' => t('Enabled/disabled <strong>Pan control</strong>.'),
      'rotateControl' => t('Enabled/disabled <strong>Rotate control</strong>.'),
      'zoomControl' => t('Enabled/disabled <strong>Zoom control</strong>.'),
      'scaleControl' => t('Enabled/disabled <strong>Scale control</strong>.'),
      'streetViewControl' => t('Enabled/disabled <strong>Street View Pegman control</strong>.'),
      'overviewMapControl' => t('Enabled/disabled <strong>Overview Map control</strong>.'),
      'disableDoubleClickZoom' => t('Enables/disables zoom and center on double click. Enabled by default.'),
      'draggable' => t('If false, prevents the map from being dragged. Dragging is enabled by default.'),
      'scrollwheel' => t('If false, disables scrollwheel zooming on the map. The scrollwheel is enabled by default.')
    ),
    '#description' => t('Select the map options you want to activate'),
    '#default_value' => variable_get('skmap_options', array('panControl', 'zoomControl', 'streetViewControl', 'draggable', 'scrollwheel')),
  );

  $form['#submit'][] = 'skmap_setting_submit';

  return system_settings_form($form);
}

function skmap_setting_submit($form, &$form_state){
  variable_set('skmap_libraries_shakemap_min', $form_state['values']['shakemap_js']);
  variable_set('skmap_libraries_infobox', $form_state['values']['use_infobox']);
  variable_set('skmap_libraries_oms', $form_state['values']['use_oms']);
  $content_type = array();
  foreach($form_state['values']['node_types'] as $type){
    if($type){
      $content_type[] = $type;
    }
  }
  variable_set('skmap_settings_node_types', $content_type);
  //map options variables
  $map_options = array();
  foreach($form_state['values']['map_options'] as $key => $option){
    $map_options[$key] = $option;
  }
  variable_set('skmap_settings_other_page', $form_state['values']['other_page']);
  variable_set('skmap_options', $map_options);
}

?>