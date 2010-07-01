; Make the Google Auth profile.

; This make file is based off buildkit.
includes[buildkit] = "../buildkit/drupal-org.make"

projects[gdata][subdir] = "custom"
projects[gdata][type] = "module"
projects[gdata][download][type] = "svn"
projects[gdata][download][url] = "https://devseed.svn.cvsdude.com/distro/sandbox/jose/gdata/"

projects[autoload][version] = "1.4"
projects[autoload][subdir] = "contrib"

projects[libraries][version] = "1.0-alpha1"
projects[libraries][subdir] = "contrib"

projects[zend][version] = "2"
projects[zend][subdir] = "contrib"

libraries[zend][download][type] = "get"
libraries[zend][download][url] = "http://framework.zend.com/releases/ZendFramework-1.10.6/ZendFramework-1.10.6.tar.gz"
libraries[zend][directory_name] = "Zend"

projects[oauth_common][version] = "2.0-beta2"
projects[oauth_common][subdir] = "contrib"

projects[inputstream][version] = "1.0"
projects[inputstream][subdir] = "contrib"
