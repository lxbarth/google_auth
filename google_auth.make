; Make the Google Auth profile.

; This make file is based off buildkit.
includes[buildkit] = "../buildkit/drupal-org.make"

projects[gftables][subdir] = "custom"
projects[gftables][type] = "module"
projects[gftables][download][type] = "svn"
projects[gftables][download][url] = "https://devseed.svn.cvsdude.com/sandbox/jose/gftables/"

projects[autoload][version] = "1.4"
projects[autoload][subdir] = "contrib"

projects[libraries][version] = "1.0-alpha1"
projects[libraries][subdir] = "contrib"

projects[zend][version] = "1"
projects[zend][subdir] = "contrib"

libraries[zend][download][type] = "get"
libraries[zend][download][url] = "http://framework.zend.com/releases/ZendFramework-1.10.6/ZendFramework-1.10.6-minimal.tar.gz"
libraries[zend][directory_name] = "Zend"

projects[oauth_common][type] = "module"
projects[oauth_common][download][type] = "cvs"
projects[oauth_common][download][module] = "contributions/modules/oauth_common"
projects[oauth_common][download][revision] = "HEAD"
projects[oauth_common][subdir] = "contrib"
; http://drupal.org/node/846370
projects[oauth_common][patch][] = "http://drupal.org/files/issues/oauth_common_token_length.patch"
projects[oauth_common][patch][] = "http://drupal.org/files/issues/842990-3_oauth_common_authorization_contexts.patch"
projects[oauth_common][patch][] = "http://drupal.org/files/issues/846734-1_consumer.patch"

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
