; Make the Google Auth profile.

; This make file is based off buildkit.
includes[buildkit] = "../buildkit/drupal-org.make"

projects[gdata][subdir] = "custom"
projects[gdata][type] = "module"
projects[gdata][download][type] = "svn"
projects[gdata][download][url] = "https://devseed.svn.cvsdude.com/distro/sandbox/jose/gdata/"
