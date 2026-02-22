#include"Application.h"
#include<iostream>
#include<thread>
#include<chrono>
namespace Verge {

	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		while (true) {

			std::cout << "------Welcome to Verge Engine------\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}