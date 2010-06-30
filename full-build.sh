#!/bin/bash

# This script will create a full build of the project.
#
# Run from writeable directory.
#
# Requires full access to repositories.
#
# @todo .git directory is not being deleted as expected.
#

# Retrieve Drupal.
DATE=`date "+%Y-%m-%dT%H-%M-%S"`
DIRNAME="google_auth-"$DATE
drush make --yes --tar full-build.make $DIRNAME
