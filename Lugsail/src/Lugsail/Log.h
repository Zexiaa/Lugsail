#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Lugsail {

	class LUGSAIL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define LS_CORE_TRACE(...)	::Lugsail::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LS_CORE_INFO(...)	::Lugsail::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LS_CORE_WARN(...)	::Lugsail::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LS_CORE_ERROR(...)	::Lugsail::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LS_CORE_FATAL(...)	::Lugsail::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LS_TRACE(...)	::Lugsail::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LS_INFO(...)	::Lugsail::Log::GetClientLogger()->info(__VA_ARGS__)
#define LS_WARN(...)	::Lugsail::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LS_ERROR(...)	::Lugsail::Log::GetClientLogger()->error(__VA_ARGS__)
#define LS_FATAL(...)	::Lugsail::Log::GetClientLogger()->fatal(__VA_ARGS__)