--------------------------------------------------------------------------------
-- TODO: Add console builds linked with ncurses
-- TODO: Testing in Windows
--------------------------------------------------------------------------------

-- if not os.isdir("../debug") then os.mkdir("../debug") end

--------------------------------------------------------------------------------

solution "EVE"
	location (_WORKING_DIR.."/"..(_ACTION or ""))
	targetdir (_WORKING_DIR.."/../bin") 

	configurations { "Release", "Debug" }
	platforms { "x64", "x32" }

	configuration { "windows" }
		defines { "WINDOWS" }

	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }

--------------------------------------------------------------------------------

project "EVE"
	uuid "D20CBF50-D363-11E2-8B8B-0800200C9A66"
	kind "WindowedApp"
	language "C++"
	includedirs { 
		"../src",
		"../external/evds/include",
		"../external/simc/include",
	}
	files {
			"../src/**",
	}
	links { "evds", "simc" }
	defines { "EVE_SIM" }

	configuration { "windows" }
		links { "OgreMain", "OIS" }

	configuration { "linux" }
		links { "m", "pthread", "GL", "Xxf86vm", "X11", "OgreMain", "OIS", "boost_thread", "boost_system" }
		linkoptions { "-lstdc++" }

--------------------------------------------------------------------------------

SIMC_STANDALONE = false
EVDS_STANDALONE = false

dofile("./../external/simc/support/premake4_common.lua");
dofile("./../external/simc/support/premake4.lua");
dofile("./../external/evds/support/premake4.lua");
