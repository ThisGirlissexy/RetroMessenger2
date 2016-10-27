# Constants


# Download a file
# $1 = URL of file (http, ftp), $2 = output filename
function download_file()
{
  URL=$1
  FILENAME=$2

  if [ -f "$DOWNLOAD_DIR/$FILENAME" ]; then
     echo "SKIPPED:   $FILENAME (already downloaded)"
  else
     echo "DOWNLOAD:  $FILENAME"
     $WGET "$URL" -O "$DOWNLOAD_DIR/$FILENAME"
     echo
  fi
}

function check_command()
{
  which $1 2>/dev/null >/dev/null
  if [ "$?" == "1" ]; then
     echo "Command '$1' not found! Aborting."
     exit
  fi
}

