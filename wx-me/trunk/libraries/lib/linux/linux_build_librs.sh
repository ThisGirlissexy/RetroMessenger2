echo ========= Install necessary tools =========
sudo apt-get install build-essential qt4-dev-tools subversion libqt4-dev g++

echo ========= miniupnpc =========

mkdir src
mkdir lib

cd src
if test -r "miniupnpc-1.3.tar.gz" ; then echo Already downloaded; else
    wget http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.3.tar.gz

    
    tar -xzvf miniupnpc-1.3.tar.gz
fi

cd miniupnpc-1.3
make
cd ..
cd ..
cp src/miniupnpc-1.3/libminiupnpc.a lib/


echo ========= openssl =========


cd src

if test -r "openssl-0.9.8k.tar.gz" ; then echo Already downloaded; else
    wget http://www.openssl.org/source/openssl-0.9.8k.tar.gz
    tar -xzvf openssl-0.9.8k.tar.gz
fi

cd openssl-0.9.8k
./config --openssldir=/etc/ssl-xpgp no-shared 
make -j2
cd ..
cd ..

cp src/openssl-0.9.8k/*.a lib/

cd src

if test -r "gpgme-1.1.8.tar.bz2" ; then echo Already downloaded; else
    wget ftp://ftp.gnupg.org/gcrypt/gpgme/gpgme-1.1.8.tar.bz2
    tar xjvf gpgme-1.1.8.tar.bz2
    cd gpgme-1.1.8
    ./configure
    make -j2
    cd ..
fi

cd ..
cd src

if test -r "libgpg-error-1.7.tar.bz2" ; then echo Already downloaded; else
    wget ftp://ftp.gnupg.org/gcrypt/libgpg-error/libgpg-error-1.7.tar.bz2
    tar xjvf libgpg-error-1.7.tar.bz2
    cd libgpg-error-1.7
    ./configure
    make -j2
    cd ..
fi
cd ..


exit

echo ========= retroshare =========


cd src
svn co https://retroshare.svn.sourceforge.net/svnroot/retroshare/trunk retroshare
cd ..

cd src/retroshare/libretroshare/src/
qmake-qt4 && make -j2
