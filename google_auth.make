; Make the Google Auth profile.

; This make file is based off buildkit.
includes[buildkit] = "../buildkit/drupal-org.make"

projects[gdata][subdir] = "custom"
projects[gdata][type] = "module"
projects[gdata][download][type] = "svn"
projects[gdata][download][url] = "https://devseed.svn.cvsdude.com/distro/sandbox/jose/gdata/"

projects[autoload][version] = "1.4"
projects[autoload][subdir] = "contrib"

projects[zend][version] = "2"
projects[zend][subdir] = "contrib"

projects[oauth_common][version] = "2.0-beta2"
projects[oauth_common][subdir] = "contrib"
