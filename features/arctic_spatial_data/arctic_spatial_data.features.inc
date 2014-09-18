<?php
/**
 * @file
 * sevilleta_spatial_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sevilleta_spatial_data_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sevilleta_spatial_data_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sevilleta_spatial_data_node_info() {
  $items = array(
    'spatial_data' => array(
      'name' => t('Spatial Data'),
      'base' => 'node_content',
      'description' => t('This content type is for entering GIS and imagery data.  '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
