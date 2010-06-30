#!/bin/sh

echo "This will rebuild the entire project. All uncommitted changes will be lost."
echo "Do you want to continue? (y/n):"
read PROCEDE
if [ "$PROCEDE" != "y" ]; then
  echo "cancelled."
  exit
fi

rm -Rf modules/ themes/ libraries/
drush make --yes --working-copy --no-core --contrib-destination=. google_auth.make
git checkout modules && git checkout themes
