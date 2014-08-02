<?php
/**
 * @file
 * Provide the views image cube plugin object with default options and form.
 */

/**
 * Implementation of views_plugin_style().
 */
class views_imagecube_style_plugin extends views_plugin_style {
  function option_definition() {
    $options = parent::option_definition();
    unset($options['grouping']);
    $options['height'] = array('default' => '220');
    $options['width'] = array('default' => '250');
    $options['direction'] = array('default' => 'random');
    $options['speed'] = array('default' => '2000');
    $options['pause'] = array('default' => '2000');
    $options['repeat'] = array('default' => TRUE);
    $options['selection'] = array('default' => 'forward');
    $options['full3D'] = array('default' => TRUE);
    $options['segments'] = array('default' => '20');
    $options['reduction'] = array('default' => '30');
    $options['shading'] = array('default' => TRUE);
    $options['expansion'] = array('default' => '10');
    $options['opacity'] = array('default' => '0.8');
    return $options;
  }

  /**
   * Hook_form implementation.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['grouping']);

    $form['width'] = array(
      '#type' => 'textfield',
      '#title' => t('Width'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['width'],
      '#description' => t('Set image style width'),
    );
    $form['height'] = array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['height'],
      '#description' => t('Set image style height'),
    );
    $form['rotation'] = array(
      '#type' => 'fieldset',
      '#title' => t('Rotation'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#parents' => array('style_options'),
    );
    $form['rotation']['direction'] = array(
      '#type' => 'select',
      '#title' => t('Direction'),
      '#default_value' => $this->options['direction'],
      '#description' => t('The direction in which to rotate the cube.'),
      '#options' => array(
        'random' => t('Random'),
        'up' => t('Up'),
        'down' => t('Down'),
        'left' => t('Left'),
        'right' => t('Right'),
      ),
    );
    $form['rotation']['selection'] = array(
      '#type' => 'select',
      '#title' => t('Selection'),
      '#default_value' => $this->options['selection'],
      '#description' => t('Determine how the next image to be shown is selected.'),
      '#options' => array(
        'random' => t('Random'),
        'forward' => t('Forward'),
        'backward' => t('Backward'),
      ),
    );
    $form['rotation']['speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Animation speed'),
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => $this->options['speed'],
      '#description' => t('The number of milliseconds that it takes for each rotation to complete..'),
    );
    $form['rotation']['repeat'] = array(
      '#type' => 'checkbox',
      '#title' => t('Repeat'),
      '#default_value' => $this->options['repeat'],
      '#description' => t('Set to true to automatically rotate the cube to a new image after pausing the time below. Set to false to only rotate on demand.'),
    );
    $form['rotation']['pause'] = array(
      '#type' => 'textfield',
      '#title' => t('Timing pause'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['pause'],
      '#field_suffix' => ' ' . t('miliseconds'),
      '#description' => t('The number of milliseconds to pause between rotations of the cube.'),
    );
    $form['effects'] = array(
      '#type' => 'fieldset',
      '#title' => t('Effects'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#parents' => array('style_options'),
    );
    $form['effects']['opacity'] = array(
      '#type' => 'textfield',
      '#title' => t('Opacity'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['opacity'],
      '#description' => t('The maximum opacity for the highlight and shadow. Valid values are 0.0 to 1.0.'),
    );
    $form['effects']['full3D'] = array(
      '#type' => 'checkbox',
      '#title' => t('Full 3D'),
      '#description' => t('Set to true to display a full 3D cube with perspective. Set to false to use the original ("flat") transition.'),
      '#default_value' => $this->options['full3D'],
    );
    $form['effects']['full3D_effects'] = array(
      '#type' => 'fieldset',
    );
    $form['effects']['full3D_effects']['segments'] = array(
      '#type' => 'textfield',
      '#title' => t('Segments'),
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => $this->options['segments'],
      '#description' => t('The number of segments to use for the full3D effect. A higher number gives a smoother look to the cube but means more work for the animation.'),
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[full3D]"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['effects']['full3D_effects']['reduction'] = array(
      '#type' => 'textfield',
      '#title' => t('Reduction'),
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => $this->options['reduction'],
      '#description' => t('The number of pixels by which the back edges of the cube are reduced for the full3D effect.'),
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[full3D]"]' => array('checked' => TRUE),
        ),
      ),
    );
    $form['effects']['full3D_effects']['expansion'] = array(
      '#type' => 'textfield',
      '#title' => t('Expansion'),
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => $this->options['expansion'],
      '#description' => t('The number of pixels by which the front edge of the cube is expanded for the full3D effect.'),
      '#states' => array(
        'visible' => array(
          ':input[name="style_options[full3D]"]' => array('checked' => TRUE),
        ),
      ),
    );
  }
  /**
   * Disable the "Use pager" option for this display.
   */
  function validate() {
    $errors = parent::validate();
    if ($this->display->handler->use_pager()) {
      $errors[] = t('The Views Image Cube style is not supposed to use a pager. Disable the "Use a pager" option for this display.');
    }
    return $errors;
  }
}
