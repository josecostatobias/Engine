project "GlassEngine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "c++20"
    staticruntime "on"
    pchheader "gpch.hpp"
    pchsource "src/gpch.cpp"

    
    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    
    files
    {
        "include/**.hpp",
        "src/**.cpp"
    }


    includedirs
    {
        "include",
        "%{include_dir.SDL3}"
    }



    filter "system:windows"
    systemversion "latest"
    
    defines
    {
        "PLATFORM_WINDOWS",
        "WIN32_LEAN_AND_MEAN",
        "_CRT_SECURE_NO_WARNINGS",
    }

    filter "configurations:Debug"
        defines 
        {
            "DEBUG",
            "LOG_WARNING",
            "LOG_INFORMATION",
            "LOG_DEBUG",
            "LOG_TRACE",
            "LOG_DEFAULT",
        }
        buildoptions "/MDd"
        symbols "on"
    
    filter "configurations:Release"
        defines 
        {
            "RELEASE",
        }
        buildoptions "/MD"
        optimize "on"