LIBS="$LIBS opensslxpgp"
LIB_OPENSSLXPGP_FILENAME=openssl-0.9.7g-xpgp-0.1c.tgz
LIB_OPENSSLXPGP_URLBASE=http://www.lunamutt.com/retroshare
LIB_OPENSSLXPGP_DIRNAME=openssl-0.9.7g-xpgp-0.1c

function build_opensslxpgp()
{
    LIBNAME=opensslxpgp
    cd $SRC_DIR
    if [ ! -d "$LIB_OPENSSLXPGP_DIRNAME" ]; then
       echo "Unpacking $LIBNAME"
       tar -zxf "$DOWNLOAD_DIR/$LIB_OPENSSLXPGP_FILENAME" "-C$SRC_DIR"
    fi
    cd "$SRC_DIR/$LIB_OPENSSLXPGP_DIRNAME"
    PLATFORM=`cat Makefile|grep ^PLATFORM|sed -e 's/.*=//'`
    if [ "$PLATFORM" == "dist" ]; then
        echo "Configuring openssl-xpgp."
        ./Configure mingw
    fi
    DONE=0
    if [ -f libcrypto.a -a -f libssl.a ]; then
       DONE=1
    fi
    if [ $DONE == 0 ]; then
        echo "Building $LIBNAME"
        make
    fi
    DONE=0
    if [ -f libcrypto.a -a -f libssl.a ]; then
       DONE=1
    fi
    if [ $DONE == 0 ]; then
       echo "Build of $LIBNAME failed!"
       exit
    fi
    echo "DONE: $LIBNAME"
    cd ..
}

function download_opensslxpgp()
{
  download_file $LIB_OPENSSLXPGP_URLBASE/$LIB_OPENSSLXPGP_FILENAME $LIB_OPENSSLXPGP_FILENAME
}
