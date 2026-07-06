#!/usr/bin/env bash
set -e
cp -r /opt/work /home/builder/
cd work

find /opt/work -print
find /home/builder -print

cat ./PKGBUILD
makepkg -f
cp ./*.pkg.tar.zst /workspace/
