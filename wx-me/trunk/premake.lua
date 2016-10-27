-- ---------------------------------------------------------------------------
-- premake.lua - Premake script to generate build files for all RetroMessenger
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

-- INCLUDES ------------------------------------------------------------------
--
dofile( "premake/wxpresets.lua" )

-- OPTIONS -------------------------------------------------------------------
--
addoption( "dynamic-runtime", "Use the dynamicly loadable version of the runtime." )

-- PROJECT SETTINGS ----------------------------------------------------------
--
project.name	= "RetroMessenger"
project.bindir	= "bin"
project.libdir	= "lib"

-- CONFIGURATIONS ------------------------------------------------------------
--
--project.configs = { "Release", "Debug" }

-- PACKAGES ------------------------------------------------------------------
--
dopackage( "retromessenger.lua" )

-- EXTRAS --------------------------------------------------------------------
--
function doclean(cmd, arg)
	docommand(cmd, arg)
	os.rmdir("bin")
end
