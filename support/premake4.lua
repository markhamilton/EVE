-- TODO: Add console builds linked with ncurses

-- This makes the script a little bit cleaner


--------------------------------------------------------------------------------
-- EVE Flight Simulator 
--------------------------------------------------------------------------------
solution "EVE"
	debugdir "../debug"
	location (_WORKING_DIR.."/"..(_ACTION or ""))
	targetdir (_WORKING_DIR.."/../bin") 

if not os.isdir("../debug") then os.mkdir("../debug") end

project "EVE"
	uuid "D20CBF50-D363-11E2-8B8B-0800200C9A66"
	language "C++"
	includedirs { "../include" }
	files { "../source/**" }
	-- links { "libOIS", "libOgreMain" }
	defines { "EVE_SIM" }
	kind "WindowedApp"

	configurations {
		"Debug",
		"Release"
	}

	platforms { "x32", "x64" }

	configuration { "windows" }
		defines { "WINDOWS" }

	configuration { "windows", "x64" }
		defines { "WIN64" }

	configuration { "linux" }
		links { "m", "pthread" }
		linkoptions { "-lstdc++" }

	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }



--------------------------------------------------------------------------------
-- Irrlicht Graphics Engine 
--------------------------------------------------------------------------------

project "Irrlicht"
	uuid "A42ADB24-5672-1A42-8A85-5820260C9566"
	language "C++"
	includedirs {
		"../external/irrlicht/include",
		"../external/irrlicht/source/aesGladman",
		"../external/irrlicht/source/jpeglib",
		"../external/irrlicht/source/libpng",
		"../external/irrlicht/source/bzip2",
		"../external/irrlicht/source/lzma",
		"../external/irrlicht/source/zlib",
	}
	files {
		"../external/irrlicht/source/Irrlicht/*.cpp",
		"../external/irrlicht/source/Irrlicht/aesGladman/*.cpp",
		"../external/irrlicht/source/Irrlicht/aesGladman/*.h",
		"../external/irrlicht/source/Irrlicht/jpeglib/*.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/*.h",
		"../external/irrlicht/source/Irrlicht/libpng/source/*.c",
		"../external/irrlicht/source/Irrlicht/libpng/source/*.h",
		"../external/irrlicht/source/Irrlicht/bzip2/source/*.c",
		"../external/irrlicht/source/Irrlicht/bzip2/source/*.h",
		"../external/irrlicht/source/Irrlicht/lzma/source/*.c",
		"../external/irrlicht/source/Irrlicht/lzma/source/*.h",
		"../external/irrlicht/source/Irrlicht/zlib/source/*.c",
		"../external/irrlicht/source/Irrlicht/zlib/source/*.h",
	}
	excludes {
		"../external/irrlicht/source/Irrlicht/libpng/example.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/jmemdos.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/jmemmac.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/example.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/rdjpgcom.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/wrjpgcom.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/cdjpeg.c",
	}
	kind "StaticLib"

	configurations {
		"Debug",
		"Release"
	}

	platforms { "x32", "x64" }

	configuration { "windows" }
		defines { "WINDOWS" }

	configuration { "windows", "x64" }
		defines { "WIN64" }

	configuration { "linux" }
		linkoptions { "-lstdc++" }

	configuration "Debug"
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }

