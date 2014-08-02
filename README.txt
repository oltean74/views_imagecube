
Description
-----------
This module provides a central function for adding jQuery Image Cube
plugin elements.
For more information about Image Cube, visit the official project:
http://keith-wood.name/imageCube.html


Installation
------------
1) Place this module directory in your modules folder (this will usually be
   "sites/all/modules/").

2) Enable the module within your Drupal site at Administer -> Site Building ->
   Modules (admin/build/modules).

Usage
-----
The Views_imagecube module is used with the Views module to turn listings
of images into a cube image.

1) Install the Views module (http://drupal.org/project/views) on your Drupal
   site if you have not already.

2) Add a new view at
   Administration -> Structure -> Views (admin/structure/views).

3) Change the "Display format" of the view to "Views Image Cube".
   Click the "Continue & Edit" button to configure the rest of the View.

4) Click on the "Settings" link next to the Views Image Cube to configure
   the options for the Image Cube.

 Important!
      Click on the "Display" link under the Views Image Cube
	  and change to Views Image Cube and now you'll be able to choose
	  the 'image_field' that you want to dispaly in Image Cube style.
 Example: if you choose display format "Views Image Cube" of "fields"
          you have to change "Fields" in view edit to "View Image Cube".

Author:
Oltean Ioan
https://www.drupal.org/user/2880525
