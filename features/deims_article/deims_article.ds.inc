<?php
/**
 * @file
 * deims_article.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function deims_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'body',
        1 => 'field_files',
        2 => 'field_related_publications',
        3 => 'field_related_people',
        4 => 'field_section',
        5 => 'field_keywords',
        6 => 'field_article_date',
      ),
    ),
    'fields' => array(
      'body' => 'header',
      'field_files' => 'header',
      'field_related_publications' => 'header',
      'field_related_people' => 'header',
      'field_section' => 'header',
      'field_keywords' => 'header',
      'field_article_date' => 'header',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
  );
  $export['node|article|full'] = $ds_layout;

  return $export;
}
