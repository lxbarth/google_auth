; Instructions for making the full project. Use by running full-build.sh

core = "6.x"
projects[drupal][version] = "6.17"

projects[buildkit][type] = profile
projects[buildkit][download][type] = "cvs"
projects[buildkit][download][module] = "contributions/profiles/buildkit"
projects[buildkit][download][revision] = "DRUPAL-6--1:2010-06-30"

projects[google_auth][type] = profile
projects[google_auth][download][type] = git
projects[google_auth][download][url] = git://github.com/lxbarth/google_auth.git
