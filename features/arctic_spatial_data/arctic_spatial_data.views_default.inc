<?php
/**
 * @file
 * sevilleta_spatial_data.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sevilleta_spatial_data_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'show_spatial_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Show Spatial Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Sevilleta GIS Vector Datasets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'datatables';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_spatialdata_metadata_file' => 'field_spatialdata_metadata_file',
    'body' => 'body',
    'title' => 'title',
    'field_spatialdata_shapefile_file' => 'field_spatialdata_shapefile_file',
    'field_spatialdata_kml_file' => 'field_spatialdata_kml_file',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_spatialdata_metadata_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_spatialdata_shapefile_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_spatialdata_kml_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['elements'] = array(
    'search_box' => 1,
    'table_info' => 1,
    'save_state' => 0,
    'table_tools' => 0,
  );
  $handler->display->display_options['style_options']['layout'] = array(
    'autowidth' => 0,
    'themeroller' => 0,
    'sdom' => '',
  );
  $handler->display->display_options['style_options']['pages'] = array(
    'pagination_style' => '0',
    'length_change' => 0,
    'display_length' => '10',
  );
  /* Field: Content: Metadata */
  $handler->display->display_options['fields']['field_spatialdata_metadata_file']['id'] = 'field_spatialdata_metadata_file';
  $handler->display->display_options['fields']['field_spatialdata_metadata_file']['table'] = 'field_data_field_spatialdata_metadata_file';
  $handler->display->display_options['fields']['field_spatialdata_metadata_file']['field'] = 'field_spatialdata_metadata_file';
  $handler->display->display_options['fields']['field_spatialdata_metadata_file']['label'] = '';
  $handler->display->display_options['fields']['field_spatialdata_metadata_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spatialdata_metadata_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spatialdata_metadata_file']['click_sort_column'] = 'fid';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '240',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Description (click for FGDC metadata)';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid_1]">[title]</a>
<br/>
FGDC metadata: [field_spatialdata_metadata_file]
<br/>
[body] ';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Shapefile */
  $handler->display->display_options['fields']['field_spatialdata_shapefile_file']['id'] = 'field_spatialdata_shapefile_file';
  $handler->display->display_options['fields']['field_spatialdata_shapefile_file']['table'] = 'field_data_field_spatialdata_shapefile_file';
  $handler->display->display_options['fields']['field_spatialdata_shapefile_file']['field'] = 'field_spatialdata_shapefile_file';
  $handler->display->display_options['fields']['field_spatialdata_shapefile_file']['label'] = '';
  $handler->display->display_options['fields']['field_spatialdata_shapefile_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spatialdata_shapefile_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spatialdata_shapefile_file']['click_sort_column'] = 'fid';
  /* Field: Content: KML file */
  $handler->display->display_options['fields']['field_spatialdata_kml_file']['id'] = 'field_spatialdata_kml_file';
  $handler->display->display_options['fields']['field_spatialdata_kml_file']['table'] = 'field_data_field_spatialdata_kml_file';
  $handler->display->display_options['fields']['field_spatialdata_kml_file']['field'] = 'field_spatialdata_kml_file';
  $handler->display->display_options['fields']['field_spatialdata_kml_file']['label'] = '';
  $handler->display->display_options['fields']['field_spatialdata_kml_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spatialdata_kml_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spatialdata_kml_file']['click_sort_column'] = 'fid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Download';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[field_spatialdata_shapefile_file]<br/><br/>
[field_spatialdata_kml_file] ';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'spatial_data' => 'spatial_data',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Keywords (field_spatialdata_keywords) */
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['id'] = 'field_spatialdata_keywords_tid';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['table'] = 'field_data_field_spatialdata_keywords';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['field'] = 'field_spatialdata_keywords_tid';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['expose']['operator_id'] = 'field_spatialdata_keywords_tid_op';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['expose']['label'] = 'GIS Theme';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['expose']['operator'] = 'field_spatialdata_keywords_tid_op';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['expose']['identifier'] = 'field_spatialdata_keywords_tid';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['vocabulary'] = 'spatial_data';
  $handler->display->display_options['filters']['field_spatialdata_keywords_tid']['error_message'] = FALSE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'gis/vector';
  $export['show_spatial_data'] = $view;

  return $export;
}
