#!/bin/sh

# Create /rsbuild link if it doesn't exist yet
if [ ! -L /rsbuild ]; then
    FIRST2CHARS=`echo "$0"|sed -e 's/^\(..\).*$/\1/'`
    if [ "$FIRST2CHARS" != "./" ]; then
        echo "On first invocation, this script must be called using ./<script>. Aborting."
        exit
    fi
    HERE=`pwd`
    ln -s "$HERE" /rsbuild
fi

# Set us up
. /rsbuild/scripts/setup.inc

# Create directories if necessary
[ ! -d "$DOWNLOAD_DIR" ] && mkdir "$DOWNLOAD_DIR"
[ ! -d "$SRC_DIR" ] && mkdir "$SRC_DIR"

# Run the scripts that create the environment, in ascending order.
for s in scripts/?_*.sh; do
   . $s
done
