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

## Set up OAuth and Fusion Tables

1. Go to [Google and register your domain](http://code.google.com/apis/accounts/docs/RegistrationForWebAppsAuto.html#new),
you will obtain an OAuth consumer key and an OAuth consumer secret.
2. Go to your site's admin/settings/oauth/google and enter the key and secret.
3. Go to your Drupal user account, click on the "Google" tab and request and
authorize a token.
