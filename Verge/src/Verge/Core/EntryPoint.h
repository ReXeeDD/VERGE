#pragma once

#include"Application.h"

extern Verge::Application* Verge::CreateApplication();
int main(int argc,char** argv) {
	Verge::Log::Init();
	ZH_CORE_ERROR("Initializing Log");
	ZH_INFO("Hello");
	auto app = Verge::CreateApplication();
	
	app->Run();

	delete app;
}