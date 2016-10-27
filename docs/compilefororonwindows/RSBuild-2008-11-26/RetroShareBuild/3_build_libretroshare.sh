#!/bin/sh

. /rsbuild/scripts/setup.inc

cd $SRC_DIR/$RS_WORKDIRNAME/libretroshare/src
make

if [ ! -f lib/libretroshare.a ]; then
   echo "Compile failed. You are on your own, sorry :("
   exit
fi

cat << __EOF__

libretroshare.a successfully compiled!

To compile the GUI, leave CYGWIN, start the "QT 4.4.3 Command Prompt"
and run 4_*.bat from this directory.
__EOF__
