--------------------------------------------------------------------------------
-- TODO: Add console builds linked with ncurses
-- TODO: Testing in Windows
--------------------------------------------------------------------------------

-- if not os.isdir("../debug") then os.mkdir("../debug") end

--------------------------------------------------------------------------------

solution "EVE"
	location (_WORKING_DIR.."/"..(_ACTION or ""))
	targetdir (_WORKING_DIR.."/../bin") 

	configurations { "Debug", "Release" }
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
		"../external/glfw/include",
		"../external/evds/include",
		"../external/simc/include",
	}
	files {
			"../source/**",
			"../include/**",
	}
	links { "glfw", "evds", "simc" }
	defines { "EVE_SIM" }
	kind "WindowedApp"

	configuration { "linux" }
		links { "m", "pthread" }
		linkoptions { "-lstdc++" }

--------------------------------------------------------------------------------

-- TODO: something needs to invoke cmake first

project "glfw"
	uuid "D15A53B8-EDE5-8C4E-90AF-09F47C48DA45"
	kind "StaticLib"
	language "C"
	includedirs {
		"../external/glfw/include",
		"../external/glfw/deps",
	}
	files {
		"../external/glfw/src/internal.h",
		"../external/glfw/src/clipboard.c",
		"../external/glfw/src/context.c",
		"../external/glfw/src/gamma.c",
		"../external/glfw/src/init.c",
		"../external/glfw/src/input.c",
		"../external/glfw/src/joystick.c",
		"../external/glfw/src/monitor.c",
		"../external/glfw/src/time.c",
		"../external/glfw/src/window.c",
	}
	configuration { "windows" }
		files { "../external/glfw/src/win32_*.c" }
		files { "../external/glfw/src/wgl_*.c" }
		includedirs { "../external/config/glfw_win32" }
	configuration { "linux" }
		files { "../external/glfw/src/x11_*.c" }
		includedirs { "../external/config/glfw_x11" }

--------------------------------------------------------------------------------

SIMC_STANDALONE = false
EVDS_STANDALONE = false

dofile("./../external/simc/support/premake4_common.lua");
dofile("./../external/simc/support/premake4.lua");
dofile("./../external/evds/support/premake4.lua");
