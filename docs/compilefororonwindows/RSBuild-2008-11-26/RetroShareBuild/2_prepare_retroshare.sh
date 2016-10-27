#!/bin/sh
. /rsbuild/scripts/setup.inc

RS_REV=r767

cd "$SRC_DIR"

if [ ! -d "$RS_WORKDIRNAME" ]; then
    echo "Checking out RetroShare $RS_REV from Subversion repository..."
    echo
    echo "NOTE: You may need to press 'p' to accept SourceForge's certificate"
    echo "      permanently if this is the first time using SourceForge."
    echo
    svn co -$RS_REV https://retroshare.svn.sourceforge.net/svnroot/retroshare/trunk "$RS_WORKDIRNAME"
    if [ "$?" != "0" ]; then
        echo "Checkout gave an error. Fix problem, delete 'src/$RS_WORKDIRNAME', try again :)"
        echo "Running this script again without doing this will just say things are ready,"
        echo "but they are not..."
        exit
    fi

    echo "Creating patch..."
    
    # Copy the template patch and patch the patch before applying it
    cd "$RS_WORKDIRNAME"
    cp "$PATCH_DIR/RetroShare-$RS_REV.diff-template" rs.diff
    for l in $LIBS; do
       libname=`echo "$l" | tr "[a-z]" "[A-Z]"`
       varname=`echo "LIB_${libname}_DIRNAME"`
       eval libdirname=\$$varname
       #set -x
       cat rs.diff | sed -e "s/__${varname}__/${libdirname}/g" > rs.diff.tmp
       #set +x
       rm rs.diff
       mv rs.diff.tmp rs.diff
    done

    echo "Applying patch..."
    patch -p1 < rs.diff
    echo
fi

cat << __EOF__
RetroShare ready to be built! Run 3_*.sh in cygwin, then 4_*.bat in the
"QT 4.4.3 Command Prompt".

When you see it works, update to the latest development version by doing:

   cd src/$RS_WORKDIRNAME; svn update; make clean

Then recompile again.

Good luck - and have fun!
__EOF__

