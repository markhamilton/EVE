--------------------------------------------------------------------------------
-- TODO: Add console builds linked with ncurses
-- TODO: Testing in Windows
-- TODO: Whittle down the irrlicht build to remove unnecessary files
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
			"../external/irrlicht/source/Irrlicht/MacOSX",
			"../external/irrlicht/source/Irrlicht",
			"../external/irrlicht/include",
			"../external/glfw/deps"
		}
		files {
			"../external/irrlicht/source/Irrlicht/*.cpp",
			"../external/irrlicht/source/Irrlicht/*.h",
			"../external/irrlicht/source/Irrlicht/MacOSX/*.h",
			"../external/irrlicht/source/Irrlicht/zlib/*.c",
			"../external/irrlicht/source/Irrlicht/zlib/*.h",
			"../external/irrlicht/source/Irrlicht/jpeglib/*.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/*.h",
			"../external/irrlicht/source/Irrlicht/libpng/*.c",
			"../external/irrlicht/source/Irrlicht/libpng/*.h",
			"../external/irrlicht/source/Irrlicht/lzma/*.c",
			"../external/irrlicht/source/Irrlicht/lzma/*.h",
			"../external/irrlicht/source/Irrlicht/bzip2/*.c",
			"../external/irrlicht/source/Irrlicht/bzip2/*.h",
			"../external/irrlicht/source/Irrlicht/aesGladman/*.cpp",
			"../external/irrlicht/source/Irrlicht/aesGladman/*.h",
		}
		excludes {
			"../external/irrlicht/source/Irrlicht/jpeglib/jmemdos.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/jmemmac.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/ansi2knr.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/rdjpgcom.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/wrjpgcom.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/cdjpeg.c",
			"../external/irrlicht/source/Irrlicht/jpeglib/example.c",
			"../external/irrlicht/source/Irrlicht/libpng/example.c",
			"../external/irrlicht/source/Irrlicht/libpng/pngtest.c",
			"../external/irrlicht/source/Irrlicht/bzip2/bzip2.c",
			"../external/irrlicht/source/Irrlicht/bzip2/dlltest.c",
		}

--------------------------------------------------------------------------------

project "EVE"
	uuid "D20CBF50-D363-11E2-8B8B-0800200C9A66"
	language "C++"
	includedirs { 
		"../include",
		"../external/evds/include",
		"../external/simc/include",
		"../external/irrlicht/include",
	}
	files {
			"../source/**",
			"../include/**",
	}
	links { "evds", "simc", "Irrlicht" }
	defines { "EVE_SIM" }
	kind "WindowedApp"

	configuration { "windows" }
		links { "" }

	configuration { "linux" }
		links { "m", "pthread", "GL", "Xxf86vm", "X11" }
		linkoptions { "-lstdc++" }

--------------------------------------------------------------------------------

SIMC_STANDALONE = false
EVDS_STANDALONE = false

dofile("./../external/simc/support/premake4_common.lua");
dofile("./../external/simc/support/premake4.lua");
dofile("./../external/evds/support/premake4.lua");
