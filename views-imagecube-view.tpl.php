<?php
/**
 * @file
 * Main view template.
 */
?>

  <?php if ($rows): ?>

<div id="views-image-cube-<?php print $cubes_id; ?>" style="width: <?php print $width; ?>px; height: <?php print $height; ?>px;">
      <?php foreach ($rows as $row): ?>
        <?php print $row ?>
      <?php endforeach; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
