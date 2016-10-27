#
# This file should need no editing
#

WGET=wget
BASE_DIR=/rsbuild
DOWNLOAD_DIR=$BASE_DIR/download
SRC_DIR=$BASE_DIR/src
SCRIPT_DIR=$BASE_DIR/scripts
PATCH_DIR=$BASE_DIR/patches
RS_WORKDIRNAME=RetroShare-work

# Pull in the utilities we need
. $SCRIPT_DIR/utils.inc

# Pull in definition files for the libraries we want to work with
LIBS=""
for x in $SCRIPT_DIR/lib_*.inc; do
  . $x
done
