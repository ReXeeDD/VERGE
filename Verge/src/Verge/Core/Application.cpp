#include"Application.h"
#include"../Physics/Vec2.h"
#include<iostream>
#include<thread>
#include<chrono>
namespace Verge {

	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		Vec2 v1{ 1.0f,2.0f };
		Vec2 v2{ 1.0f,2.0f };

		std::cout << v1 + v2 << std::endl;
		

	}
}