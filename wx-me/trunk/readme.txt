RetroMessenger
-------------
Introduction:
	RetroMessenger aims to be an small, simple and secure instant messenger.

Take the time to read it and lets talk about what doesn't make sense and needs to be updated.

Start at the index. 
     https://retromessenger.svn.sourceforge.net/svnroot/retromessenger/docs/index.html


Read as well the wiki of the project:
http://retromessenger.wiki.sourceforge.net/space/pagelist
http://retromessenger.wiki.sourceforge.net/retromessenger_howto-compile-libretroshare.html
and see the build instructions for libretroshare at the original place of libretroshare.

http://retroshare.sf.net
http://retroshare.sourceforge.net/wiki/index.php/Win32CompileQtCreator

	
	Use Premake, for your platform, to generate the build files of your choice.
	
	REMEMBER: The way you get new additions and updates to the build files you
	need to run	Premake. This is means that it is good practice to run Premake
	before starting	to build or develop RetroMessenger.

Build Steps:
	- There are included batch/sh script that you can run to just simplify running
	  and creating the build files. Just run it to create the necessary build files.
	  You can skip the next step if you use those. NOTE: wxWidgets is expected to be
	  installed before running on Linux.
		* Files:
			Windows:	create_build_files.bat
			Linux:		create_build_files.sh
	  
	- To create the needed build files type:
	
		* CodeLite Projects and workspace:
			Windows:	premake\premake.exe --target cl-gcc [--unicode] [--with-wx-shared]
			Linux:		premake/premake --target cl-gcc [--unicode] [--with-wx-shared]
			
		* GNU makefiles:
			Windows:	premake\premake.exe --target gnu [--unicode] [--with-wx-shared]
			Linux:		premake/premake --target gnu [--unicode] [--with-wx-shared]
			
		* Code::Blocks Projects and workspace:
			Windows:	premake\premake.exe --target cb-gcc [--unicode] [--with-wx-shared]
			Linux:		premake/premake --target cb-gcc [--unicode] [--with-wx-shared]

	- For CodeLite, use the generated RetroMessenger.workspace to build RetroMessenger.
	
	- For GNU makefiles type: (Assumes you have properly setup your system to build
	  with gcc or MinGW)
	  
		* Release:
			make CONFIG=Release
		
		* Debug:
			make
	
	- For Code::Blocks, use the generated RetroMessenger.workspace to build RetroMessenger.

Includes:
	- RetroMessenger

Notes:
	- CodeLite is a free cross-platform IDE and it can be found here:
	  http://codelite.org

	- Premake can be found here:
	  http://premake.sourceforge.net
	
	- Subversion is a great free cross-platform version control manager.
	  It can be found here:
	  http://subversion.tigris.org

	- Code::Blocks is a free cross-platform IDE and it can be found here:
	  http://codeblocks.org

	- So please update your install of wxFormBuilder to properly open the .fbp file.

	For details on where to find the update see this 	(http://forum.wxformbuilder.org/index.php?topic=498.0) or build wxFormBuilder from the svn trunk.

	If on Ubuntu you can get the build from one of the wxFormBuilders apt repositories. Here is the link with those details:
    https://launchpad.net/~rjmyst3/+archive

Enjoy,
  The RetroMessenger Team
