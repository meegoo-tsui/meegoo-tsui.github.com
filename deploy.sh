#! /bin/sh

echo git@github.com:meegoo-tsui/meegoo-tsui.github.com.git | rake setup_github_pages
rake deploy

