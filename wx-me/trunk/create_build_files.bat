@echo off

premake\premake.exe --target cl-gcc --unicode
echo done...
echo.

premake\premake.exe --target gnu --unicode
echo done...
echo.

echo Done generating all project files for RetroMessenger.