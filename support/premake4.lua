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

	configuration { "windows", "x64" }
		defines { "WIN64" }

	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }


--------------------------------------------------------------------------------

project "EVE"
	uuid "D20CBF50-D363-11E2-8B8B-0800200C9A66"
	language "C++"
	includedirs { 
		"../include",
		"../external/evds/include",
		"../external/simc/include",
	}
	files {
			"../source/**",
			"../include/**",
	}
	links { "evds", "simc" }
	defines { "EVE_SIM" }
	kind "WindowedApp"

	configuration { "windows" }
		links { "" }

	configuration { "linux" }
		links { "m", "pthread", "GL", "glut" }
		linkoptions { "-lstdc++" }

--------------------------------------------------------------------------------

SIMC_STANDALONE = false
EVDS_STANDALONE = false

dofile("./../external/simc/support/premake4_common.lua");
dofile("./../external/simc/support/premake4.lua");
dofile("./../external/evds/support/premake4.lua");
