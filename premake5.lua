include_dir = {}
include_dir["SDL3"]         = "%{wks.location}/ThirdParty/SDL/include"

extern_lib_dir = {}


workspace "GlassEngine"
     architecture "x64"
    --  startproject "Editor"
    configurations{ "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    flags
    {
        "MultiProcessorCompile"
    }


    
group "ThirdParty"

group ""

group "Engine"
   include "GlassEngine"
group ""