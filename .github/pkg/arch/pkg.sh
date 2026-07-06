#!/usr/bin/env bash
set -e
cp -r /opt/work /home/builder/
cat ./PKGBUILD
makepkg -f
cp ./*.pkg.tar.zst /opt/dist/
