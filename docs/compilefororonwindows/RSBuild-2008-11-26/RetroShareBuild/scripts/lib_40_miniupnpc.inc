LIBS="$LIBS miniupnpc"
LIB_MINIUPNPC_FILENAME=miniupnpc-1.0.tar.gz
LIB_MINIUPNPC_URLBASE=http://miniupnp.free.fr/files/download.php?file=
LIB_MINIUPNPC_DIRNAME=miniupnpc-1.0

function build_miniupnpc()
{
    LIBNAME=miniupnpc

    cd "$SRC_DIR"
    if [ ! -d "$LIB_MINIUPNPC_DIRNAME" ]; then
       echo "Unpacking $LIBNAME"
       tar -zxf "$DOWNLOAD_DIR/$LIB_MINIUPNPC_FILENAME" "-C$SRC_DIR"
    fi

    cd "$SRC_DIR/$LIB_MINIUPNPC_DIRNAME"
    if [ ! -f .patched ]; then
       patch -p1 <  $PATCH_DIR/$LIB_MINIUPNPC_DIRNAME.diff
       touch .patched
    fi

    if [ ! -f libminiupnpc.a ]; then
        echo "Building $LIBNAME."
        make -f Makefile.mingw
        echo
        echo "*** NOTE: Ignore linking errors above. We only need libminiupnpc.a"
        echo
    fi
    if [ ! -f libminiupnpc.a ]; then
       echo "Build of $LIBNAME failed!"
       exit
    fi
    echo "DONE: $LIBNAME"
    cd ..
}

function download_miniupnpc()
{
  download_file "$LIB_MINIUPNPC_URLBASE$LIB_MINIUPNPC_FILENAME" $LIB_MINIUPNPC_FILENAME
# ftp://ftp.trolltech.com/qt/source/qt-win-opensource-4.4.3-mingw.exe \
}
