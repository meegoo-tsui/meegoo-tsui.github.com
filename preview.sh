#! /bin/sh

set -e
./clean.sh

rake generate
rake preview
