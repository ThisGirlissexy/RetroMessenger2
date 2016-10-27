#!/bin/sh
#

set -e

# Premake
PREMAKE_DIR=premake

# Autodetect wxWidgets settings
if wx-config --unicode >/dev/null 2>/dev/null; then
	unicode="--unicode"
fi
#if ! wx-config --debug >/dev/null 2>/dev/null; then
#	debug="--disable-wx-debug"
#fi
debug=

$PREMAKE_DIR/premake --target cl-gcc $unicode $debug --with-wx-shared $1
echo done...
echo 
#
$PREMAKE_DIR/premake --target gnu $unicode $debug --with-wx-shared $1
echo done...
echo 
#
echo Done generating all project files for RetroMessenger.
#
