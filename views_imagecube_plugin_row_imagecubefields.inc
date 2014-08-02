<?php
/**
 * @file
 * Contains the base row style plugin.
 */

/**
 * The basic 'fields' row plugin.
 */
class views_imagecube_plugin_row_imagecubefields extends views_plugin_row {
  function option_definition() {
    $options = parent::option_definition();
    $options['image_field'] = array('default' => '');
    return $options;
  }

  /**
   * Hook_form implementation.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Pre-build all of our option lists for the dials and switches that follow.
    $fields = array('' => t('None'));
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if ($label = $handler->label()) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }

    $form['image_field'] = array(
      '#type' => 'select',
      '#title' => t('Image field'),
      '#options' => $fields,
      '#default_value' => $this->options['image_field'],
      '#description' => t('Select the field that will be used as the image field.'),
    );
  }
}
