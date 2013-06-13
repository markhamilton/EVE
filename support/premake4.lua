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



