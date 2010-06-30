#!/bin/bash

# This script will create a full dev build of the project.
#
# Requires full access to repositories.
#

drush make --yes --working-copy full-build.make google_auth
