include_dir = {}
include_dir["SDL3"]         = "%{wks.location}/ThirdParty/SDL/include"
include_dir["Imgui"]         = "%{wks.location}/ThirdParty/Imgui"
include_dir["VulkanSDK"] = "C:/VulkanSDK/1.3.290.0/Include"

extern_lib_dir = {}
extern_lib_dir["SDL3"]         = "%{wks.location}/ThirdParty/SDL/VisualC/x64/Debug"
extern_lib_dir["VulkanSDK"] = "C:/VulkanSDK/1.3.290.0/Lib"

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
include "ThirdParty/Imgui"
group ""

group "Engine"
   include "GlassEngine"
group ""