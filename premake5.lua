workspace "Lugsail"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lugsail"
	location "Lugsail"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor-libs/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LS_PLATFORM_WINDOWS",
			"LS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "LS_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "LS_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Lugsail/vendor-libs/spdlog/include",
		"Lugsail/src"
	}

	links 
	{
		"Lugsail"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LS_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "LS_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LS_DIST"
		symbols "On"