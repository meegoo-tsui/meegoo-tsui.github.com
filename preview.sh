#! /bin/sh

set -e
./clean.sh

bundle exec rake generate
bundle exec rake preview
