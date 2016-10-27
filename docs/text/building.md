# Building RetroMessenger from source

## Introduction
RetroMessenger aims to be an small, simple, and secure instant messenger. This document will describe the process required to build RetroMessenger from source code. Please pay close attention to every step, as all of them are required.

## Prerequisites

-	Windows, Linux, OpenMoko, or Mac OSX (not tested but should work)
-	[wxWidgets](wxwidgets_install.html "wxWidgets install instructions") v2.8.x or higher
-	[GCC](gcc_install.html "GCC install instructions") v3.x.x or higher
-	[Subversion](svn_install.html)

## Steps

### 1. Generate Project Files

1.	There are included batch/sh script that you can run to simplify creating the build files. Run the script, for your selected platform, to create the necessary build files.

	**You can skip the next step if you use those.**

	-	*Windows:*
	
		`create_build_files.bat`
		
	-	*Linux:*
		
		`create_build_files.sh`
	
2.	[OPTIONAL] To create the needed build files type:
	
	-	CodeLite Projects and workspace:
	
		- 	*Windows:*
		
			`premake\premake.exe --target cl-gcc [--unicode] [--with-wx-shared]`
			
		-	*Linux:*
		
			`premake/premake --target cl-gcc [--unicode] [--with-wx-shared]`

	-	GNU makefiles:
	
		-	*Windows:*
			
			`premake\premake.exe --target gnu [--unicode] [--with-wx-shared]`
		-	*Linux:*
			
			`premake/premake --target gnu [--unicode] [--with-wx-shared]`
			
	-	Code::Blocks Projects and workspace:
	
		-	*Windows:*
			
			premake\premake.exe --target cb-gcc [--unicode] [--with-wx-shared]
		-	*Linux:*
			
			premake/premake --target cb-gcc [--unicode] [--with-wx-shared]

### 2. Build RetroMessenger

**CodeLite**

-	Use the generated `RetroMessenger.workspace` to build RetroMessenger.
	
**GNU makefiles** <small>(Assumes you have properly setup your system to build with gcc or MinGW)</small>

-	*Release:*

	`make CONFIG=Release`
	
-	*Debug:*
	
	`make`
	
**Code::Blocks**

-	Use the generated `RetroMessenger.workspace` to build RetroMessenger.


# Final Thoughts

Use Premake, for your platform, to generate the build files of your choice.

**REMEMBER:** The way you get new additions and updates to the build files you need to run Premake. This is means that it is good practice to run Premake before starting to build or develop RetroMessenger.

[Back](index.html)
