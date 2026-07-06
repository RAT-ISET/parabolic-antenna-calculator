#!/usr/bin/env bash
set -e
cp -r /opt/work /home/builder/
echo ./PKGBUILD
makgpkg -f
cp ./*.pkg.tar.zst /opt/dist/
