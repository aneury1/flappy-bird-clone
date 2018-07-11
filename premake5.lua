-- premake5.lua
workspace "Flappy-bird-udacity"
   configurations { "Debug", "Release" }

project "Flappy-bird-udacity"
   kind "ConsoleApp"
   language "C++"
    cppdialect "C++11"
   targetdir "bin/%{cfg.buildcfg}"
   files { "**.h", "**.c", "**.cpp", "**.hpp" }
   links { "sfml-system","sfml-main" ,"sfml-window", "sfml-audio", "sfml-graphics","sfml-network" }
   
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"