#pragma once
#include "Core.h"

namespace Verge {

	class VERGE_API Application {
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	Application* CreateApplication();
}