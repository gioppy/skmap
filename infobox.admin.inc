<?php
//$Id$

function infobox_setting(){
  $form = array();

  $form['skmap_infobox'] = array(
    '#type' => 'fieldset',
    '#title' => t('Infobox style'),
    '#description' => t('Upload the elemnts to create an infobox: the background and close images.'),
  );

  $form['skmap_infobox']['image_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Base path to the infobox images'),
    '#description' => t('The base path where the infobox images are stored, relative to the Drupal base path.<br />The images must be <strong>background.png</strong> (background image of the infobox) and <strong>close.png</strong> (close button).'),
    '#default_value' => variable_get('skmap_markers_path', '/sites/default/files/skmap/infobox/'),
  );

  $form['skmap_infobox']['pixel_offset'] = array(
    '#type' => 'textfield',
    '#title' => t('Infobox offset'),
    '#description' => t('The offset of the infobox expressed link Size object, like <code>-100, -100</code>'),
    '#default_value' => variable_get('shakemap_infobox_offset', ''),
  );

  $form['#submit'][] = 'infobox_setting_submit';

  return system_settings_form($form);
}

function infobox_setting_submit($form, &$form_state){
  variable_set('shakemap_infobox_offset', $form_state['values']['pixel_offset']);
  variable_set('shakemap_infobox_use', $form_state['values']['use_infobox']);
}

?>