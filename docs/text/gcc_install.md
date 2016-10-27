# GCC install instructions

## Purpose

Describe the install process of the GCC compiler. In this document we are using GCC v4.2.1, but other versions after three should work.

## Windows

### GCC Compiler

1.	Download [MinGW v4.2.1-dw2.3](http://wxpack.sourceforge.net/Main/Downloads).
2.	Run the installer.
3.	Make sure to install it to `...\MinGW`, not `...\MinGW4`. (This makes setting up CodeLite easier)
3.	You are done installing MinGW v4.2.1-dw2.3 on Windows.

### MSYS Build Environment

These instructions are based on MinGW.org instructions found [here](http://www.mingw.org/node/18)

1.	Install [MSYS 1.0.10](http://downloads.sourceforge.net/mingw/MSYS-1.0.10.exe). I usually install it in `C:\msys\1.0`, but you can use any directory that you prefer.
2.	Next, the post install process will ask for the directory where MinGW was installed to. Enter "`c:/mingw`". If you make a mistake, you can change it by editing the "`C:\msys\1.0\etc\fstab`" file, make sure to use 'LF line endings. An example fstab may contain:
	c:/mingw /mingw
3.	Install [MSYS DTK 1.0](http://downloads.sourceforge.net/mingw/msysDTK-1.0.1.exe) in `C:\msys\1.0`.
4.	Install [MSYS Core 1.0.11](http://downloads.sourceforge.net/mingw/msysCORE-1.0.11-2007.01.19-1.tar.bz2). It is an archive. Untar it in `C:\msys\1.0`.

Now you should have a cyan "M" link on the Desktop. When you double-click on it, a terminal should be launched.

## Linux

### Debian Distros (Ubuntu, Kubuntu, Xubuntu)

1.	Open a treminal. (Click `Applications->Accessories->Terminal`)
2.	Type `sudo aptitude install build-essential gdb` and press 'Enter'.
3.	After it says you are done, GCC and the GDB debugger has been installed on your system.

### (Comming Soon) Fedora Distros

[Back](building.html)
