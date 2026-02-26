#include"Application.h"
#include"../Physics/Vec2.h"
#include<iostream>
#include<thread>
#include<chrono>
#include"../Physics/RigidBody.h"
namespace Verge {

	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		Vec2 p{ 0.0f, 0.0f };
		Vec2 v{ 0.0f, 0.0f };
		Vec2 a{ 0.0f, 0.0f };
		Vec2 force{5.0f, 5.0f};
		RigidBody body(p,v,a);

		std::cout << "[POSITION]" << body.position << std::endl;

		for (int i = 0; i < 5; ++i) {
			body.ApplyForce(force);
			body.Integrate(0.1f);
			std::cout << "[POSITION]" << body.position << std::endl;
		}

	}
}