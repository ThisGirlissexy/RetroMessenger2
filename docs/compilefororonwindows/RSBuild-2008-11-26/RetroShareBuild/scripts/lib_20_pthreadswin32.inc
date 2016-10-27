LIBS="$LIBS pthreadswin32"
LIB_PTHREADSWIN32_FILENAME=pthreads-w32-2-8-0-release.tar.gz
LIB_PTHREADSWIN32_URLBASE=ftp://sourceware.org/pub/pthreads-win32
LIB_PTHREADSWIN32_DIRNAME=pthreads-w32-2-8-0-release

function build_pthreadswin32()
{
    LIBNAME=pthreads-win32
    cd $SRC_DIR
    if [ ! -d "$LIB_PTHREADSWIN32_DIRNAME" ]; then
       echo "Unpacking $LIBNAME"
       tar -zxf "$DOWNLOAD_DIR/$LIB_PTHREADSWIN32_FILENAME" "-C$SRC_DIR"
    fi

    cd "$SRC_DIR/$LIB_PTHREADSWIN32_DIRNAME"

    if [ ! -f .patched ]; then
       patch -p1 <  $PATCH_DIR/$LIB_PTHREADSWIN32_DIRNAME.diff
       touch .patched
    fi

    DONE=0
    if [ -f libpthreadGC2.a -a -f libpthreadGC2d.a ]; then
       DONE=1
    fi
    if [ $DONE == 0 ]; then
        # Need to build all of it twicce, and store the result in between
        mkdir libtmp 2>/dev/null > /dev/null
        echo "Building $LIBNAME"
        make clean GC-static
        mv *.a libtmp/
        make clean GC-static-debug
        mv *.a libtmp/
        
        # Move stuff back
        mv libtmp/*.a .
        rmdir libtmp
    fi

    DONE=0
    if [ -f libpthreadGC2.a -a -f libpthreadGC2d.a ]; then
       DONE=1
    fi

    if [ $DONE == 0 ]; then
       echo "Build of $LIBNAME failed!"
       exit
    fi
    echo "DONE: $LIBNAME"
    cd ..
}

function download_pthreadswin32()
{
  download_file $LIB_PTHREADSWIN32_URLBASE/$LIB_PTHREADSWIN32_FILENAME $LIB_PTHREADSWIN32_FILENAME
}
