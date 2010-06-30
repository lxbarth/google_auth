# Google Auth

Testing Google Authentication/Authorization APIs.

## Drush make

This project must be built with [Drush Make](http://drupal.org/project/drush_make).

Use the latest DRUPAL-6--2 branch of Drush Make.

## Build for deployment

Run full-build.sh from within the google_ee profile directory. This will create
a tarball containing the entire site tree, ready to be deployed.

## Build for development

Run full-build-dev.sh from within the google_ee profile directory. This will
create a directory containing the entire site tree. All projects pointed to a 
repository will be checked out as a working copy.

## Installation

Google Auth can be installed like any other Drupal site. When the
installation process asks to select an installation profile, pick "Google
Auth".

See [Drupal Installation Guide](http://drupal.org/getting-started/install).
