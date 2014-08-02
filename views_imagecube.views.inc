<?php

/**
 * @file
 * Provide the views image cube plugin definition.
 */
function views_imagecube_views_plugins() {
  return array(
    'module' => 'views_imagecube',
    'style' => array(
      'views_imagecube' => array(
        'title' => t('Views Image Cube'),
        'theme' => 'views_imagecube_view',
        'help' => t('Display a view with Jquery Image Cube.'),
        'handler' => 'views_imagecube_style_plugin',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'imagecubefields' => array(
        'title' => t('Views Image Cube'),
        'help' => t('Choose the fields to display in Image Cube Styles.'),
        'handler' => 'views_imagecube_plugin_row_imagecubefields',
        'theme' => 'views_imagecube_view_imagecubefields',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
