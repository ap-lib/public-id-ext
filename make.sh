#!/bin/bash

set -e

cd src

echo "🛠️  Running phpize..."
phpize

echo "⚙️  Configuring extension..."
./configure --enable-public-id

echo "🔨  Building..."
make

echo "✅ Done!"


sudo make install

phpize --clean
find . -type f -name "*.dep" -delete