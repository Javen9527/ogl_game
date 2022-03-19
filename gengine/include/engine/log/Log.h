#pragma once

#include "dllDefine.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <memory>

namespace ge
{

	class GE_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return m_engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> m_engineLogger;
		static std::shared_ptr<spdlog::logger> m_clientLogger;
	};

} // namespace ge

// engine log
#define GE_FATAL(...) ::ge::Log::GetEngineLogger()->fatal(__VA_ARGS__)
#define GE_ERROR(...) ::ge::Log::GetEngineLogger()->error(__VA_ARGS__)
#define GE_WARN(...) ::ge::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define GE_INFO(...) ::ge::Log::GetEngineLogger()->info(__VA_ARGS__)
#define GE_TRACE(...) ::ge::Log::GetEngineLogger()->trace(__VA_ARGS__)

// engine log
#define APP_FATAL(...) ::ge::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define APP_ERROR(...) ::ge::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_WARN(...) ::ge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_INFO(...) ::ge::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_TRACE(...) ::ge::Log::GetClientLogger()->trace(__VA_ARGS__)

