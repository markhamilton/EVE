solution "proland"
   platforms { "x32", "x64" }
   configurations { "Debug", "Release" }

   -- Setup environment
   location (_ACTION)
   targetdir "../bin"
   debugdir "../data"

   -- Include default libraries
   includedirs { "../ork",
                 "../ork/libraries",
                 "../ork/libraries/tinyxml",
                 "../dependencies",
                 "../dependencies/glew/include",
                 "../dependencies/pthreads/Pre-built.2/include",
                 "../dependencies/glut",
                 "../dependencies/AntTweakBar/include",
                 "../dependencies/tiff/include" }
   configuration { "x32" }
      libdirs { "../dependencies/glew/lib",
                "../dependencies/pthreads/Pre-built.2/lib/x86",
                "../dependencies/glut",
                "../dependencies/AntTweakBar/lib",
                "../dependencies/tiff/lib"  }
   configuration { "x64" }
      libdirs { "../dependencies/glew64/lib",
                "../dependencies/pthreads/Pre-built.2/lib/x64",
                "../dependencies/glut",
                "../dependencies/AntTweakBar/lib",
                "../dependencies/tiff/lib" }

   -- Debug/Release configurations and correct debug suffix
   configuration "Debug*"
      defines { "DEBUG", "TIXML_USE_STL", "STBI_NO_STDIO", "STBI_NO_WRITE" , "GLUT_NO_WARNING_DISABLE",
                "GLUT_NO_LIB_PRAGMA", "_STDCALL_SUPPORTED", "_CRT_SECURE_NO_WARNINGS", "_M_IX86", "_MBCS" }
      flags { "Symbols" }
      --linkoptions { "/OPT:NOREF" }
      buildoptions { "/wd4251","/wd4091","/wd4244","/wd4305" }
      
   configuration "Release*"
      defines { "TIXML_USE_STL", "STBI_NO_STDIO", "STBI_NO_WRITE" , "GLUT_NO_WARNING_DISABLE",
                "GLUT_NO_LIB_PRAGMA", "_STDCALL_SUPPORTED", "_CRT_SECURE_NO_WARNINGS", "_M_IX86", "_MBCS" }
      flags { "Optimize", "Symbols" }
      --linkoptions { "/OPT:NOREF" }
      buildoptions { "/wd4251","/wd4091","/wd4244","/wd4305" }

   -- Generate suffixes
   configuration { "x64", "Debug*" }
      targetsuffix "d64"
   configuration { "x32", "Debug*" }
      targetsuffix "d"
   configuration { "x64", "Release*" }
      targetsuffix "64"

   -- Windows-specific
   configuration { "windows" }
      defines { "_CRT_SECURE_NO_WARNINGS","WIN32" }
   configuration { "windows", "x64" }
      defines { "WIN64" }


--------------------------------------------------------------------------------
   project "ork"
      kind "SharedLib"
      language "C++"
      files { "../ork/ork/**",
              "../ork/libraries/tinyxml/**",
              "../ork/libraries/stbi/**" }
      vpaths { ["include/**"] = "../ork/ork/**.h",
               ["source/**"]  = "../ork/ork/**.cpp",
               ["libraries/**"] = "../ork/libraries/**" }

      defines { "ORK_API=__declspec(dllexport)" }
      
      configuration { "x32", "windows" }
         links { "pthreadVC2", "glut32", "glew32", "opengl32", "glu32", "libtiff" }
      configuration { "x64", "windows" }
         links { "pthreadVC2", "glut64", "glew32", "opengl32", "glu32", "libtiff" }


--------------------------------------------------------------------------------
   project "proland"
      kind "SharedLib"
      language "C++"
      includedirs { "../proland/core/sources",
                    "../proland/terrain/sources",
                    "../proland/atmo/sources" }
                    
      files { "../proland/core/sources/**",
              "../proland/terrain/sources/**",
              "../proland/atmo/sources/**" }
              
      vpaths { ["core/include/**"]    = "../proland/core/sources/proland/**.h",
               ["core/source/**"]     = "../proland/core/sources/proland/**.cpp",
               ["terrain/include/**"] = "../proland/terrain/sources/proland/**.h",
               ["terrain/source/**"]  = "../proland/terrain/sources/proland/**.cpp",
               ["atmo/include/**"]    = "../proland/atmo/sources/proland/**.h",
               ["atmo/source/**"]     = "../proland/atmo/sources/proland/**.cpp" }

      defines { "ORK_API=__declspec(dllimport)", "PROLAND_API=__declspec(dllexport)" }
      defines { "roundf=floor" }

      links { "ork" }

      configuration { "x32", "windows" }
         links { "pthreadVC2", "glut32", "glew32", "opengl32", "glu32", "libtiff" }
      configuration { "x64", "windows" }
         links { "pthreadVC2", "glut64", "glew32", "opengl32", "glu32", "libtiff" }


--------------------------------------------------------------------------------
   function proland_example(name,exname)
      project ("proland_"..name.."_"..exname)
         kind "ConsoleApp"
         language "C++"
         includedirs { "../proland/core/sources",
                       "../proland/"..name.."/sources",
                       "../proland/"..name.."/examples/"..exname }
         files { "../proland/"..name.."/examples/"..exname.."/**" }
         vpaths { ["include/**"] = "../proland/"..name.."/examples/"..exname.."/**.h",
                  ["source/**"]  = "../proland/"..name.."/examples/"..exname.."/**.cpp" }

         defines { "ORK_API=__declspec(dllimport)", "PROLAND_API=__declspec(dllimport)" }
         links { "ork", "proland" }

--         configuration { "x32", "windows" }
--            links { "pthreadVC2", "glut32", "glew32", "opengl32", "glu32", "libtiff" }
--         configuration { "x64", "windows" }
--            links { "pthreadVC2", "glut64", "glew32", "opengl32", "glu32", "libtiff" }
   end

   proland_example ("terrain", "exercise3")
   proland_example ("terrain", "exercise4")
   proland_example ("terrain", "exercise5")

--   proland_library ("core")
--   proland_library ("atmo")
--   proland_library ("edit")
 --   proland_library ("forest")
--   proland_library ("graph")
 --   proland_library ("ocean")
--   proland_library ("river")

--   proland_library ("terrain")
--   proland_example ("terrain", "exercise1")
--     includedirs { "../proland/ocean/sources" }
--     links { "proland_ocean" }
-- proland_example ("terrain", "exercise2")
--   links { "proland_edit" }
--[[   proland_example ("terrain", "exercise3")
   proland_example ("terrain", "exercise4")
   proland_example ("terrain", "exercise5")]]--

-- FIXME: copy glut.h to GL/glut.h
