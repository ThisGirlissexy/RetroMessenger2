#!/bin/sh
DATE=`date "+%Y-%m-%d"`
FNAME=RetroShareBuild-$DATE.zip
RSB=RetroShareBuild
cd ../..

rm -f "$FNAME"

#tar zcf $FNAME $RSB/?_* $RSB/scripts $RSB/patches
zip -r $FNAME $RSB/?_* $RSB/scripts $RSB/patches $RSB/doc
ls -l $FNAME
