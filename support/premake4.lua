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
	links { "OIS", "OGRE", "OGRE-Paging" }
	kind "WindowedApp"
	
	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }
	
	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }


-- TODO: Add paths for OGRE3D (cross-platform)
-- TODO: Add console builds linked with ncurses
