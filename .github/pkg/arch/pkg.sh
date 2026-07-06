#!/usr/bin/env bash
set -e
cp -r /opt/work /home/builder/
cd work
cat ./PKGBUILD
makepkg -f
cp ./*.pkg.tar.zst /opt/dist/
