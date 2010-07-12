; Make the Google Auth profile.

; This make file is based off buildkit.
includes[buildkit] = "../buildkit/drupal-org.make"

projects[autoload][version] = "1.4"
projects[autoload][subdir] = "contrib"

projects[libraries][version] = "1.0-alpha1"
projects[libraries][subdir] = "contrib"

projects[oauth][subdir] = "custom"
projects[oauth][download][type] = "git"
projects[oauth][download][url] = "git://github.com/josereyero/oauth.git"
projects[oauth][download][branch] = "master"

projects[oauth_google][subdir] = "custom"
projects[oauth_google][download][type] = "git"
projects[oauth_google][download][url] = "git://github.com/josereyero/oauth_google.git"
projects[oauth_google][download][branch] = "master"

projects[gdata][subdir] = "custom"
projects[gdata][download][type] = "git"
projects[gdata][download][url] = "git://github.com/josereyero/gdata.git"
projects[gdata][download][branch] = "master"

projects[zend][version] = "1"
projects[zend][subdir] = "contrib"

libraries[zend][download][type] = "get"
libraries[zend][download][url] = "http://framework.zend.com/releases/ZendFramework-1.10.6/ZendFramework-1.10.6-minimal.tar.gz"
libraries[zend][directory_name] = "Zend"

projects[feeds][type] = "module"
projects[feeds][download][type] = "cvs"
projects[feeds][download][module] = "contributions/modules/feeds"
projects[feeds][download][revision] = "HEAD"
projects[feeds][subdir] = "contrib"

projects[feeds_ft][subdir] = "custom"
projects[feeds_ft][type] = "module"
projects[feeds_ft][download][type] = "git"
projects[feeds_ft][download][url] = "git://github.com/lxbarth/feeds_ft.git"
projects[feeds_ft][download][branch] = "master"

projects[inputstream][version] = "1.0"
projects[inputstream][subdir] = "contrib"
