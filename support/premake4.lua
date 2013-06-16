--------------------------------------------------------------------------------
-- TODO: Add console builds linked with ncurses
--------------------------------------------------------------------------------

-- if not os.isdir("../debug") then os.mkdir("../debug") end

--------------------------------------------------------------------------------

solution "EVE"
	-- debugdir "../debug"
	location (_WORKING_DIR.."/"..(_ACTION or ""))
	targetdir (_WORKING_DIR.."/../bin") 

	configurations { "Debug", "Release" }
	platforms { "x32", "x64" }

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
		"../external/irrlicht/include"
	}
	files { "../source/**" }
	links { "Irrlicht", "png" }
	defines { "EVE_SIM" }
	kind "WindowedApp"

	configuration { "linux" }
		libdirs { "/usr/lib/x86_64-linux-gnu" } 
		links { "m", "pthread", "GL" }
		linkoptions { "-lstdc++" }

--------------------------------------------------------------------------------

project "Irrlicht"
	uuid "A42ADB24-5672-1A42-8A85-5820260C9566"
	language "C++"
	defines { "_IRR_STATIC_LIB_" }
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
		"../external/irrlicht/source/Irrlicht/libpng/*.c",
		"../external/irrlicht/source/Irrlicht/libpng/*.h",
		"../external/irrlicht/source/Irrlicht/bzip2/*.c",
		"../external/irrlicht/source/Irrlicht/bzip2/*.h",
		"../external/irrlicht/source/Irrlicht/lzma/*.c",
		"../external/irrlicht/source/Irrlicht/lzma/*.h",
		"../external/irrlicht/source/Irrlicht/zlib/*.c",
		"../external/irrlicht/source/Irrlicht/zlib/*.h",
	}
	excludes {
		"../external/irrlicht/source/Irrlicht/libpng/example.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/example.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/jmemdos.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/jmemmac.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/rdjpgcom.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/wrjpgcom.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/cdjpeg.c",
		"../external/irrlicht/source/Irrlicht/jpeglib/jpegtran.c",
		"../external/irrlicht/source/Irrlicht/bzip2/dlltest.c",
		"../external/irrlicht/source/Irrlicht/bzip2/bzip2.c",
	}
	kind "StaticLib"

	configuration { "windows" }
		links { "opengl32" }

--------------------------------------------------------------------------------
