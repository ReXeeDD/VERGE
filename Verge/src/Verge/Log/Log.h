#pragma once
#include <memory>
#include"../Core/Core.h"
#include"spdlog/spdlog.h"
namespace Verge {
	class VERGE_API Log {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		#pragma warning(push)
		#pragma warning(disable : 4251)
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
		#pragma warning(pop)
	};
}
//Core Logger macros
#define ZH_CORE_ERROR(...) ::Verge::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZH_CORE_INFO(...)  ::Verge::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZH_CORE_WARN(...)  ::Verge::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZH_CORE_FATAl(...)  ::Verge::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Logger macros
#define ZH_ERROR(...) ::Verge::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZH_INFO(...)  ::Verge::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZH_WARN(...)  ::Verge::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZH_FATAl(...)  ::Verge::Log::GetClientLogger()->fatal(__VA_ARGS__)