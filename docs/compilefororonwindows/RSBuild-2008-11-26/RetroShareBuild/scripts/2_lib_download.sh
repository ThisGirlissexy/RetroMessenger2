echo Entering download directory
if [ ! -d "$DOWNLOAD_DIR" ]; then
  echo "Download directory not found!"
  exit
fi
cd $DOWNLOAD_DIR

for l in $LIBS; do
  download_$l
done

cd ..
