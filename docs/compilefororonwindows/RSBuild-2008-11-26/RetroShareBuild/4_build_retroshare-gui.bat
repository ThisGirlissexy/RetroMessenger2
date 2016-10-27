@rem Sorry, no energy to fix error-checking etc in Windows .bat-files

cd src\RetroShare-work\retroshare-gui\src

cd games\qcheckers
qmake
call make
cd ..\..

cd apps\smplayer
qmake
call make
cd ..\..

qmake
call make
