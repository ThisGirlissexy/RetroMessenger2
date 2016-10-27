-- ---------------------------------------------------------------------------
-- retromessenger.lua - Premake script to build the GUI portion of
--
-- Copyright (c) 2008 Ryan Pusztai & RetroMessenger Team.
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License along
-- with this program; if not, write to the Free Software Foundation, Inc.,
-- 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
--
-- Please report all praise, requests, bugs and problems to the project
-- team & admins: http://sourceforge.net/projects/retromessenger
-- ---------------------------------------------------------------------------

-- GENERAL SETUP -------------------------------------------------------------
--
package.name								= "RetroMessenger"
package.language							= "c++"
package.kind								= "winexe"
package.target								= package.name
package.config["Debug"].target				= package.target .. "d"

-- PRE-BUILD SETUP -----------------------------------------------------------
--

-- HELPER FUNCTIONS -----------------------------------------------------------
--
function RemoveFiles( fileList )
	if type( fileList ) ~= "table" then
		error( "Type missmatch error occured in RemoveFiles()" )
	end

	for _, fileName in ipairs( fileList ) do
		if os.fileexists( fileName ) then
			os.remove( fileName )
		end
	end
end

-- COMPILER SETTINGS ----------------------------------------------------------
--
-- Build Flags
package.buildflags							= { "no-main" }
if options["dynamic-runtime"] then
	package.config["Release"].buildflags	= { "no-symbols", "optimize" }
else
	package.config["Debug"].buildflags		= { "static-runtime" }
	package.config["Release"].buildflags	= { "static-runtime", "no-symbols", "optimize" }
end

-- Defined Symbols
package.config["Debug"].defines				= { "DEBUG", "_DEBUG" }
package.config["Release"].defines			= { "NDEBUG" }

-- Files
package.files								= { matchfiles( "src/*.cpp", "src/*.h" ) }

package.excludes							= {}


-- LINKER SETTINGS 

if (windows) then

-- Include paths
package.includepaths 						= {
--												"libraries/kadc",
												"libraries/miniupnpc-1.3",
												"libraries/pthreads-w32-2-8-0-release",
--												"libraries/zlib-1.2.3",
												"libraries/openssl-0.9.8k/include",
												"libraries/libgpg-error-1.7/src",
												"libraries/gpgme-1.1.8/src",
												"libraries/retroshare"
											  }


package.config["Debug"].links =  {
								"libretroshared",
								"libgpg-error",
								"libgpgme",
								"libssl",
								"libcrypto",
								"libcrypt32-cygwin",
--								"kadc",
								"libminiupnpc",	
--								"libz",
								"libiphlpapi",
								"libpthreadGC2d"
								}
							
package.config["Release"].links =  {
								"libretroshare",
								"libgpg-error",
								"libgpgme",
								"libssl",
								"libcrypto",
								"libcrypt32-cygwin",
--								"kadc",
								"libminiupnpc",	
--								"libz",
								"libiphlpapi",
								"libpthreadGC2d"
							}


-- Linker directory paths.
package.libpaths							= {
												"libraries/retroshare/lib",
												"libraries/lib/windows"							
--												"libraries/kadc"
--												"libraries/lib/windows/libminiupnpc-1.3",
											  }
end

--------------

if (linux) then

-- Include paths
package.includepaths 						= {
--												"libraries/kadc",
												"libraries/miniupnpc-1.3",
--												"libraries/zlib-1.2.3",
												"libraries/openssl-0.9.8k/include",
												"libraries/libgpg-error-1.7/src",
												"libraries/gpgme-1.1.8/src",
												"libraries/retroshare"
											  }


package.config["Debug"].links =  {
									"libretroshared",
									"libgpg-error",
									"libgpgme",
									"libssl",
									"libcrypto",
									"libminiupnpc"
								}
			

package.config["Release"].links =  {
									"libretroshare",
									"libgpg-error",
									"libgpgme",
									"libssl",
									"libcrypto",
									"libminiupnpc"	
								}

			
-- Linker directory paths.
package.libpaths							= {
										"libraries/lib/linux",
										"libraries/lib/linux/gpg-related"
									  }

end


-- COMPILER SPECIFIC SETUP ----------------------------------------------------
--
if target == "gnu" or string.find( target or "", ".*-gcc" ) then
	table.insert( package.buildflags, "extra-warnings" )
	table.insert( package.buildoptions, { "-W", "-Wno-deprecated" } )
	table.insert( package.config["Release"].buildoptions, "-fno-strict-aliasing" )
	-- Set object output directory.
	if options["unicode"] then
		package.objdir						= ".obju"
	else
		package.objdir						= ".obj"
	end
end

if target == "vs2005" or target == "vs2008" then
	-- Visual C++ 2005/2008
	table.insert( package.buildflags, "seh-exceptions" )
	table.insert( package.defines, "_CRT_SECURE_NO_DEPRECATE" )
end

if target == "vs2003" then
	-- Enable re-mapping of Windows exceptions.
	package.buildoptions = { "/EHa" }
	table.insert( package.buildflags, { "no-exceptions" } )
end

-- OPERATING SYSTEM SPECIFIC SETTINGS -----------------------------------------
--
if windows then														-- WINDOWS
	table.insert( package.files, { "res/RetroMessenger.rc", "res/RetroMessenger.exe.manifest" } )
	table.insert( package.defines, { "_WIN32", "WIN32", "_WINDOWS","WINDOWS_SYS" } )
	table.insert( package.links, { "psapi", "ws2_32", "version" } )
elseif linux then													-- LINUX
	table.insert( package.links, { "pthread", "dl" } )
else																-- MACOSX
end

-- Copy images directory into bin (without svn related files) -----------------------------------------
--
for _,v in ipairs(matchrecursive("images/*")) do

 if (string.sub(v,-9) ~= ".svn-base") and (string.sub(v,-7) ~= "entries") and (string.sub(v,-11) ~= "all-wcprops") then
		s = string.sub(v,0,string.len(v)-string.len(path.getname(v))-1)
		t = ""

		for w in string.gmatch(s, "(%w+)") do
			t = t.."/"..w
		
			if (os.direxists(project.bindir..t) == false) then
				os.mkdir(project.bindir..t)
			end
		end

	os.copyfile(v,project.bindir.."/"..v)
	end
end


-- WXWIDGETS PACKAGE SETUP ----------------------------------------------------
--
-- ConfigureWxWidgets( package, altTargetName, wxVer, wxVerMinor, useAltTargetNameOnly )
ConfigureWxWidgets( package, package.name, "28", "8" )
