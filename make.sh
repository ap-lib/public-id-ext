#!/bin/bash

set -e

cd src

echo "Running phpize..."
phpize

echo "Configuring extension..."
./configure --enable-public-id

echo "Building..."
make

echo "Make Done!"


sudo make install

echo "Install Done!"

phpize --clean
find . -type f -name "*.dep" -delete
echo "Clearing Done!"