LIBS="$LIBS zlib"
LIB_ZLIB_FILENAME=zlib-1.2.3.tar.gz 
LIB_ZLIB_URLBASE=http://www.zlib.net
LIB_ZLIB_DIRNAME=zlib-1.2.3

function build_zlib()
{
    if [ ! -d "$LIB_ZLIB_DIRNAME" ]; then
       echo "Unpacking zlib."
       tar -zxf "$DOWNLOAD_DIR/$LIB_ZLIB_FILENAME" "-C$SRC_DIR"
    fi
    cd "$SRC_DIR/$LIB_ZLIB_DIRNAME"
    if [ ! -f libz.a ]; then
        echo "Building zlib."
        make
    fi
    if [ ! -f libz.a ]; then
       echo "Build of zlib failed!"
       exit
    fi
    echo "DONE: zlib"
    cd ..
}

function download_zlib()
{
  download_file $LIB_ZLIB_URLBASE/$LIB_ZLIB_FILENAME $LIB_ZLIB_FILENAME
}
