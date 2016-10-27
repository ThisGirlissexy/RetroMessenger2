CREATING A WINDOWS BUILD ENVIRONMENT FOR RETROSHARE
---------------------------------------------------

NOTE: The process below produces an executable for me, but it crashes most of
the time. Sometimes it works, but I don't know why. If anyone figures it out,
feel free fix it, or post about it in the Retroshare forums.

Start by downloading

http://www.cygwin.com/setup.exe

and running it. Then do

1 NEXT
2 Install from Internet, NEXT
3 Enter a installation dir, like for example c:\cygwin, NEXT
4 Select a dir to store packages, like for example c:\cygwin\download, NEXT
5 Select Direct Connection (or proxy if you need it), NEXT
6 Select a mirror close to you, NEXT
7 Select the following packages:

    Devel -> gcc, gcc-g++, gdb, make, patchutils, subversion
    Utils -> diffutils
    Web   -> wget
  NEXT
8 FINISH

Start the cygwin shell, cd to the directory with this buildkit (for example
cd /cygdrive/c/RetroShareBuild ) and run the scripts called
<number>_*.sh in order. When you are done with the .sh-files
you need to install QT (should be in the download-folder of this kit).

Install QT, then rebuild QT for a static build by doing this from the
"QT 4.4.3 Command Prompt":

 configure.exe -qt-sql-sqlite -qt-sql-odbc -qt-libpng -qt-libjpeg -static 
 make

This will take a pretty long time (possibly hours if you have and old computer).

Finish off by cd:ing to build-kit dir (still in the QT/Mingw shell) and run
the last .bat-file which should build

  src/RetroShare-work/retroshare-gui/src/release/RetroShare.exe

Thats it.
