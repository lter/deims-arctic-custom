<?php
/**
 * @file
 * arctic_frontpage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function arctic_frontpage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Front page';
  $page->admin_description = 'Frontpage for ';
  $page->path = 'frontpagehome';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'three_inset_left';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
          2 => 'right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '54.78004391122928',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'top' => array(
        'type' => 'region',
        'title' => 'top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => '24.842925345514914',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'bottom' => array(
        'type' => 'region',
        'title' => 'bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '20.377030743255812',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'center' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
      'three_inset_left_sidebar' => NULL,
      'three_inset_left_top' => NULL,
      'three_inset_left_middle' => NULL,
      'three_inset_left_inset' => NULL,
      'three_inset_left_bottom' => NULL,
    ),
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '438248f7-2fec-4c69-8a92-49160cf0ad0c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-66bfa623-5bc7-4a66-aa50-a0e2a952a111';
    $pane->panel = 'three_inset_left_inset';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Links to sites and weather',
      'title' => '',
      'body' => '<p style="margin: 10px;"><img alt="Weather at Toolik" src="http://www.toolik.uaf.edu/met%20graphics/currenttemppanel2.png" border="0" height="50" width="150"></p>

<p style="margin: 10px;"><a href="http://toolik.alaska.edu/edc/abiotic_monitoring/index.php" target="_blank">Toolik Weather Graphs</a></p>

<p style="margin: 10px;"><a href="arctic-lter-weather-stations">Arctic LTER Weather Stations</a></p>

<p style="margin: 10px;"><img alt="" src="http://ecosystems.mbl.edu/arc/images/webcam.jpg" style="border-width: 0pt; border-style: solid; width: 20px; height: 30px;" align="middle"> <a href="http://toolik.alaska.edu/edc/index.php" target="_blank">Toolik Webcam</a></p>

<p style="margin: 10px;"><img alt="Animatd Gif Yesterday\'s Webcam" p="" src="/sites/default/files/images/yesterdaydailygif.gif" style="width: 50px; height: 38px;"></p>

<p style="margin: 10px;"><a href="/sites/default/files/images/yesterdaydailygif.php" target="_blank">Animated Gif of yesterday\'s Webcam</a></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '66bfa623-5bc7-4a66-aa50-a0e2a952a111';
    $display->content['new-66bfa623-5bc7-4a66-aa50-a0e2a952a111'] = $pane;
    $display->panels['three_inset_left_inset'][0] = 'new-66bfa623-5bc7-4a66-aa50-a0e2a952a111';
    $pane = new stdClass();
    $pane->pid = 'new-ef73cac3-3942-4a78-874d-aa36b0c5ef27';
    $pane->panel = 'three_inset_left_middle';
    $pane->type = 'views';
    $pane->subtype = 'front_page_slideshow';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ef73cac3-3942-4a78-874d-aa36b0c5ef27';
    $display->content['new-ef73cac3-3942-4a78-874d-aa36b0c5ef27'] = $pane;
    $display->panels['three_inset_left_middle'][0] = 'new-ef73cac3-3942-4a78-874d-aa36b0c5ef27';
    $pane = new stdClass();
    $pane->pid = 'new-063cb5b5-b2dd-4b3c-8c5a-e4dfff6db8ae';
    $pane->panel = 'three_inset_left_sidebar';
    $pane->type = 'views';
    $pane->subtype = 'arctic_news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 1,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '063cb5b5-b2dd-4b3c-8c5a-e4dfff6db8ae';
    $display->content['new-063cb5b5-b2dd-4b3c-8c5a-e4dfff6db8ae'] = $pane;
    $display->panels['three_inset_left_sidebar'][0] = 'new-063cb5b5-b2dd-4b3c-8c5a-e4dfff6db8ae';
    $pane = new stdClass();
    $pane->pid = 'new-a00d67b9-b087-45d7-b67b-82ac2d066de9';
    $pane->panel = 'three_inset_left_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'user-online';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a00d67b9-b087-45d7-b67b-82ac2d066de9';
    $display->content['new-a00d67b9-b087-45d7-b67b-82ac2d066de9'] = $pane;
    $display->panels['three_inset_left_sidebar'][1] = 'new-a00d67b9-b087-45d7-b67b-82ac2d066de9';
    $pane = new stdClass();
    $pane->pid = 'new-8d42823b-f6b5-464d-8914-7d031756a0dd';
    $pane->panel = 'three_inset_left_top';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '3383',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8d42823b-f6b5-464d-8914-7d031756a0dd';
    $display->content['new-8d42823b-f6b5-464d-8914-7d031756a0dd'] = $pane;
    $display->panels['three_inset_left_top'][0] = 'new-8d42823b-f6b5-464d-8914-7d031756a0dd';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-ef73cac3-3942-4a78-874d-aa36b0c5ef27';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
