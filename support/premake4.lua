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

	project "Irrlicht"
		uuid "4b501a00-efc6-11e2-b778-0800200c9a66"
		kind "StaticLib"
		language "C++"
		includedirs {
			"../external/irrlicht/include",
			"../external/glfw/deps"
		}
		files {
			"../external/irrlicht/source/Irrlicht/*.cpp",
			"../external/irrlicht/source/Irrlicht/*.h",
			"../external/irrlicht/source/Irrlicht/jpeglib/*.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/*.h",
			"../external/irrlicht/source/Irrlicht/libpng/*.c",
			"../external/irrlicht/source/Irrlicht/libpng/*.h",
			"../external/irrlicht/source/Irrlicht/lzma/*.c",
			"../external/irrlicht/source/Irrlicht/lzma/*.h",
			"../external/irrlicht/source/Irrlicht/zlib/*.c",
			"../external/irrlicht/source/Irrlicht/zlib/*.h",
		}
		excludes {
			"../external/irrlicht/source/Irrlicht/jpeglib/jcsample.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/jdsample.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/jmemdos.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/jmemmac.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/ansi2knr.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/rdjpgcom.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/wrjpgcom.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/cdjpeg.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/example.c",
			"../external/irrlicht/source/Irrlicht/libpng/example.c",
			"../external/irrlicht/source/Irrlicht/libpng/pngtest.c",
		}

--------------------------------------------------------------------------------

project "EVE"
	uuid "D20CBF50-D363-11E2-8B8B-0800200C9A66"
	language "C++"
	includedirs { 
		"../include",
		"../external/evds/include",
		"../external/simc/include",
		"../external/glfw/include",
	}
	files {
			"../source/**",
			"../include/**",
	}
	links { "evds", "simc", "glfw" }
	defines { "EVE_SIM" }
	kind "WindowedApp"

	configuration { "windows" }
		links { "" }

	configuration { "linux" }
		links { "m", "pthread", "Xxf86vm", "GL", "X11", "Xrandr", "Xi" }
		linkoptions { "-lstdc++" }

--------------------------------------------------------------------------------

SIMC_STANDALONE = false
EVDS_STANDALONE = false

dofile("./../external/simc/support/premake4_common.lua");
dofile("./../external/simc/support/premake4.lua");
dofile("./../external/evds/support/premake4.lua");
