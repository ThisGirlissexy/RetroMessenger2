-- ----------------------------------------------------------------------------
--	Author:		RJP Computing <rjpcomputing@gmail.com>
--	Date:		04/04/2008
--	Version:	1.00-beta
--
--	NOTES:
--		- use the '/' slash for all paths.
--		- call ConfigureWxWidgets() after your project is setup, not before.
-- ----------------------------------------------------------------------------

-- Package options
addoption( "unicode", "Use the Unicode character set" )
addoption( "with-wx-shared", "Link against wxWidgets as a shared library" )

-- Configure a C/C++ package to use wxWidgets
function ConfigureWxWidgets( package, altTargetName, wxVer, wxVerMinor, useAltTargetNameOnly )
	-- Check to make sure that the package is valid.
	assert( type( package ) == "table" )

	-- Set the default values.
	local targetName = altTargetName or ""
	local wx_ver = wxVer or "28"
	local wx_ver_minor = wxVerMinor or "0"
	local useExactNaming = useAltTargetNameOnly or false

	-- Set object output directory.
	if target == "gnu" or string.find( target or "", ".*-gcc" ) then
		if options["unicode"] then
			package.objdir = ".obju"
		else
			package.objdir = ".obj"
		end
	end

	-- Set the default targetName if none is specified.
	-- NOTE: Not needed for wxWidgets, just for convienance.
	if string.len( targetName ) == 0 then
		targetName = package.name
	end

	if options["unicode"] then
		table.insert( package.buildflags, { "unicode" } )
	end

	if string.find( target or "", ".*-gcc" ) or target == "gnu" then
		table.insert( package.config["Debug"].buildoptions, { "-O0" } )
	end

	-- Set the defines.
	if options["unicode"] then
		table.insert( package.defines, { "UNICODE", "_UNICODE", "wxUSE_UNICODE" } )
	end

	table.insert( package.defines, "__WX__" )
	table.insert( package.config["Debug"].defines, { "DEBUG", "_DEBUG", "__WXDEBUG__" } )
	table.insert( package.config["Release"].defines, { "NDEBUG" } )
	if options["with-wx-shared"] then
		table.insert( package.defines, { "WXUSINGDLL" } )
	end

	if target == "vs2005" or target == "vs2008" then
		--table.insert( package.linkoptions, { "/MANIFEST:NO" } )
		table.insert( package.defines, { "wxUSE_NO_MANIFEST=1" } )
		table.insert( package.buildoptions, { "/Zc:wchar_t-" } )
	end

	if windows then
		-- ******* WINDOWS SETUP ***********
		-- *	Settings that are Windows specific.
		-- *********************************

		-- Set wxWidgets include paths
		if target == "cb-gcc" then
			table.insert( package.includepaths, { "$(#WX.include)" } )
		else
			table.insert( package.includepaths, { "$(WXWIN)/include" } )
		end

		-- Set the correct 'setup.h' include path.
		if options["unicode"] then
			if target == "cb-gcc" then
				table.insert( package.config["Debug"].includepaths, { "$(#WX.lib)/gcc_lib/mswud" } )
				table.insert( package.config["Release"].includepaths, { "$(#WX.lib)/gcc_lib/mswu" } )
				if options["with-wx-shared"] then
					table.insert( package.config["Debug"].includepaths, { "$(#WX.lib)/gcc_dll/mswud" } )
					table.insert( package.config["Release"].includepaths, { "$(#WX.lib)/gcc_dll/mswu" } )
				end
			elseif target == "gnu" or target == "cl-gcc" then
				table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/gcc_lib/mswud" } )
				table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/gcc_lib/mswu" } )
				if options["with-wx-shared"] then
					table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/gcc_dll/mswud" } )
					table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/gcc_dll/mswu" } )
				end
			else
				table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/vc_lib/mswud" } )
				table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/vc_lib/mswu" } )
				if options["with-wx-shared"] then
					table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/vc_dll/mswud" } )
					table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/vc_dll/mswu" } )
				end
			end
		else
			if target == "cb-gcc" then
				table.insert( package.config["Debug"].includepaths, { "$(#WX.lib)/gcc_lib/mswd" } )
				table.insert( package.config["Release"].includepaths, { "$(#WX.lib)/gcc_lib/msw" } )
				if options["with-wx-shared"] then
					table.insert( package.config["Debug"].includepaths, { "$(#WX.lib)/gcc_dll/mswd" } )
					table.insert( package.config["Release"].includepaths, { "$(#WX.lib)/gcc_dll/msw" } )
				end
			elseif target == "gnu" or target == "cl-gcc" then
				table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/gcc_lib/mswd" } )
				table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/gcc_lib/msw" } )
				if options["with-wx-shared"] then
					table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/gcc_dll/mswd" } )
					table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/gcc_dll/msw" } )
				end
			else
				table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/vc_lib/mswd" } )
				table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/vc_lib/msw" } )
				if options["with-wx-shared"] then
					table.insert( package.config["Debug"].includepaths, { "$(WXWIN)/lib/vc_dll/mswd" } )
					table.insert( package.config["Release"].includepaths, { "$(WXWIN)/lib/vc_dll/msw" } )
				end
			end
		end

		-- Set the linker options.
		if target == "cb-gcc" then
			table.insert( package.libpaths, { "$(#WX.lib)/gcc_lib" } )
			if options["with-wx-shared"] then
				table.insert( package.libpaths, { "$(#WX.lib)/gcc_dll" } )
			end
		elseif target == "gnu" or target == "cl-gcc" then
			table.insert( package.libpaths, { "$(WXWIN)/lib/gcc_lib" } )
			if options["with-wx-shared"] then
				table.insert( package.libpaths, { "$(WXWIN)/lib/gcc_dll" } )
			end
		else
			table.insert( package.libpaths, { "$(WXWIN)/lib/vc_lib" } )
			if options["with-wx-shared"] then
				table.insert( package.libpaths, { "$(WXWIN)/lib/vc_dll" } )
			end
		end

		-- Set wxWidgets libraries to link.
		if options["unicode"] then
			table.insert( package.config["Debug"].links, { "wsock32", "comctl32", "psapi", "ws2_32", "opengl32",
												"ole32", "winmm", "oleaut32", "odbc32", "advapi32",
												"oleaut32", "uuid", "rpcrt4", "gdi32", "comdlg32",
												"winspool", "shell32", "kernel32" } )
			table.insert( package.config["Debug"].links, 1, { "wxmsw"..wx_ver.."ud", "wxexpatd", "wxjpegd", "wxpngd",
												"wxregexud", "wxtiffd", "wxzlibd" } )
			table.insert( package.config["Release"].links, { "wsock32", "comctl32", "psapi", "ws2_32", "opengl32",
												"ole32", "winmm", "oleaut32", "odbc32", "advapi32",
												"oleaut32", "uuid", "rpcrt4", "gdi32", "comdlg32",
												"winspool", "shell32", "kernel32" } )
			table.insert( package.config["Release"].links, 1, { "wxmsw"..wx_ver.."u", "wxexpat", "wxjpeg", "wxpng", "wxregexu",
												"wxtiff", "wxzlib" } )
		else
			table.insert( package.config["Debug"].links, { "wsock32", "comctl32", "psapi", "ws2_32", "opengl32",
												"ole32", "winmm", "oleaut32", "odbc32", "advapi32",
												"oleaut32", "uuid", "rpcrt4", "gdi32", "comdlg32",
												"winspool", "shell32", "kernel32" } )
			table.insert( package.config["Debug"].links, 1, { "wxmsw"..wx_ver.."d", "wxexpatd", "wxjpegd", "wxpngd", "wxregexd",
												"wxtiffd", "wxzlibd" } )
			table.insert( package.config["Release"].links, { "wsock32", "comctl32", "psapi", "ws2_32", "opengl32",
												"ole32", "winmm", "oleaut32", "odbc32", "advapi32",
												"oleaut32", "uuid", "rpcrt4", "gdi32", "comdlg32",
												"winspool", "shell32", "kernel32" } )
			table.insert( package.config["Release"].links, 1, { "wxmsw"..wx_ver, "wxexpat", "wxjpeg", "wxpng", "wxregex",
												"wxtiff", "wxzlib" } )
		end

		-- Set the Windows defines.
		table.insert( package.defines, { "__WXMSW__", "WIN32", "_WINDOWS" } )

		-- Set the targets.
		if ( package.kind == "winexe" or package.kind == "exe" or useExactNaming ) then
			package.config["Debug"].target = targetName.."d"
			package.config["Release"].target = targetName
		else
			if string.find( target or "", ".*-gcc" ) or target == "gnu" then
				if options["unicode"] then
					package.config["Debug"].target = "wxmsw"..wx_ver..wx_ver_minor.."umd_"..targetName.."_gcc"
					package.config["Release"].target = "wxmsw"..wx_ver..wx_ver_minor.."um_"..targetName.."_gcc"
				else
					package.config["Debug"].target = "wxmsw"..wx_ver..wx_ver_minor.."md_"..targetName.."_gcc"
					package.config["Release"].target = "wxmsw"..wx_ver..wx_ver_minor.."m_"..targetName.."_gcc"
				end
			else
				if options["unicode"] then
					package.config["Debug"].target = "wxmsw"..wx_ver..wx_ver_minor.."umd_"..targetName.."_vc"
					package.config["Release"].target = "wxmsw"..wx_ver..wx_ver_minor.."um_"..targetName.."_vc"
				else
					package.config["Debug"].target = "wxmsw"..wx_ver..wx_ver_minor.."md_"..targetName.."_vc"
					package.config["Release"].target = "wxmsw"..wx_ver..wx_ver_minor.."m_"..targetName.."_vc"
				end
			end
		end

	else
	-- ******* LINUX SETUP *************
	-- *	Settings that are Linux specific.
	-- *********************************
		-- Ignore resource files in Linux.
		table.insert( package.excludes, matchrecursive( "*.rc" ) )

		-- Set wxWidgets build options.
		table.insert( package.config["Debug"].buildoptions, { "`wx-config --debug=yes --cflags`" } )
		table.insert( package.config["Release"].buildoptions, { "`wx-config --debug=no --cflags`" } )

		-- Set the wxWidgets link options.
		table.insert( package.config["Debug"].linkoptions, { "`wx-config --debug=yes --libs`" } )
		table.insert( package.config["Release"].linkoptions, { "`wx-config --libs`" } )

		-- Set the Linux defines.
		table.insert( package.defines, "__WXGTK__" )

		-- Set the targets.
		if ( package.kind == "winexe" or package.kind == "exe" or useExactNaming ) then
			package.config["Debug"].target = targetName.."d"
			package.config["Release"].target = targetName
		else
			package.config["Debug"].target = "`wx-config --debug=yes --basename`_"..targetName.."-`wx-config --release`"
			package.config["Release"].target = "`wx-config --basename`_"..targetName.."-`wx-config --release`"
		end
	end
end

function PosixLibName( targetName, isDebug )
	local dbg = isDebug or false
	local debug = "no"
	if dbg then debug = "yes" end

	return
end

function LibName( targetName, wxVer, isDebug )
	local name = ""
	-- Make the parameters optional.
	local wx_ver = wxVer or "28"

	if windows then
		local debug = ""
		local unicode = ""
		local monolithic = ""
		local vc8 = ""

		if options["unicode"] then unicode = "u" end
		if isDebug then debug = "d" end
		if options["with-wx-shared"] then monolithic = "m" end
		if target == "vs2005" and ( targetName == "flatnotebook" or targetName == "plotctrl" ) then vc8 = "vc8_" end
		name = "wxmsw"..wx_ver..unicode..monolithic..debug.."_"..vc8..targetName
	else
		local debug = "no"
		if dbg then debug = "yes" end
		name = "`wx-config --debug="..debug.." --basename`_"..targetName.."-`wx-config --release`"
	end

	return name
end

function ConfigureWxAdditions( package, libsToLink, wxVer, wxVerMinor )
	-- Check to make sure that the package is valid.
	assert( type( package ) == "table" )
	assert( type( libsToLink ) == "table" )

	local wx_ver = wxVer or "28"
	local wx_ver_minor = wxVerMinor or "0"

	-- Set wxAdditions include paths
	table.insert( package.includepaths, { "$(WXADDITIONS)/include" } )

	-- Set the linker options.
	if target == "gnu" or string.find( target or "", ".*-gcc" ) then
		table.insert( package.libpaths, { "$(WXADDITIONS)/lib/gcc_lib" } )
		if options["with-wx-shared"] then
			table.insert( package.libpaths, { "$(WXADDITIONS)/lib/gcc_dll" } )
		end
	else
		table.insert( package.libpaths, { "$(WXADDITIONS)/lib/vc_lib" } )
		if options["with-wx-shared"] then
			table.insert( package.libpaths, { "$(WXADDITIONS)/lib/vc_dll" } )
		end
	end


	-- Set wxAdditions libraries to link.LibName( targetName, wxVer, isDebug )
	local libs = {}
	for _, v in ipairs( libsToLink ) do table.insert( libs, LibName( v, wx_ver, true ) ) end
	table.insert( package.config["Debug"].links, 1, libs )
	libs = {}
	for _, v in ipairs( libsToLink ) do table.insert( libs, LibName( v, wx_ver ) ) end
	table.insert( package.config["Release"].links, 1, libs )
end
