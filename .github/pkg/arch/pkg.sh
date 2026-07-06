#!/usr/bin/env bash
set -e

find . -print
cat ./PKGBUILD
makepkg -f
