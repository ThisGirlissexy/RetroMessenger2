echo Entering src directory
if [ ! -d "$SRC_DIR" ]; then
  echo "Src directory not found!"
  exit
fi
cd $SRC_DIR

for l in $LIBS; do
    build_$l
done
