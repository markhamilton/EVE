solution "EVE"
	configurations { "Debug", "Release" }
	debugdir "../debug"

if not os.isdir("../debug") then os.mkdir("../debug") end

--------------------------------------------------------------------------------
-- EVE Flight Simulator 
--------------------------------------------------------------------------------
project "EVE"
	uuid "D20CBF50-D363-11E2-8B8B-0800200C9A66"
	language "C++"
	includedirs { "../include" }
	files { "../source/**" }
	defines { "EVE_SIM" }
	
	configuration "Debug"
		defines { "DEBUG" }
		kind "WindowedApp"
		flags { "Symbols" }
		links { "OIS", "OGRE", "OGRE-Paging" }
	
	configuration "Release"
		defines { "NDEBUG" }
		kind "WindowedApp"
		flags { "Optimize" }
		links { "OIS", "OGRE", "OGRE-Paging" }


-- TODO: Add paths for OGRE3D (cross-platform)
-- TODO: Add console builds linked with ncurses
