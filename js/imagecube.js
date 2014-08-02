(function ($) {



Drupal.behaviors.views_imagecube = {

  attach: function (context) {

    var effects = {

         direction: Drupal.settings.views_imagecube.direction,

         speed: Drupal.settings.views_imagecube.speed,

          selection: Drupal.settings.views_imagecube.selection,

         shading: Drupal.settings.views_imagecube.shading,

         opacity: Drupal.settings.views_imagecube.opacity,

         full3D: Drupal.settings.views_imagecube.full3D,

         segments: Drupal.settings.views_imagecube.segments,

         reduction: Drupal.settings.views_imagecube.reduction,

         expansion: Drupal.settings.views_imagecube.expansion,

         repeat: Drupal.settings.views_imagecube.repeat,

         pause: Drupal.settings.views_imagecube.pause,

  };

     var cubeId = Drupal.settings.views_imagecube.cube_id;

     $('#views-image-cube-'+cubeId, context).imagecube(effects);

    }

};



})(jQuery);

