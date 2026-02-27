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
		Vec2 p{ 0.0f, 0.0f };
		Vec2 v{ 0.0f, 0.0f };
		float m = 15.0f;
		
		RigidBody body(p,v,m);
		PhysicsWorld a;
		a.AddBody(body);
		while (true) {

		a.Step(0.1f);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		
		


		

		

	}
}