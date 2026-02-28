#include"Application.h"
#include"../Physics/Vec2.h"
#include<iostream>
#include<thread>
#include<chrono>
#include"../Physics/RigidBody.h"
#include"../Physics/PhysicsWorld.h"


namespace Verge {

	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		Vec2 p{ 0.0f, 10.0f };
		Vec2 v{ 0.0f, 0.0f };
		float m = 15.0f;
		
		const double FIXED_TIMESTEP= 1.0 / 60.0;
		auto lastTime = std::chrono::steady_clock::now();
		double accumulator = 0;
		RigidBody body(p,v,m);
		PhysicsWorld a;
		a.AddBody(body);
		while (true) {
			auto currentTime = std::chrono::steady_clock::now();
			auto deltaTime = duration_cast<std::chrono::duration<double>>(currentTime - lastTime).count();
			lastTime = currentTime;
			if (deltaTime > 0.25) deltaTime = 0.25;
			accumulator += deltaTime;
			while (accumulator >= FIXED_TIMESTEP) {

			a.Step(FIXED_TIMESTEP);
			accumulator -= FIXED_TIMESTEP;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		
		


		

		

	}
}