#include "Physicsworld.h"
#include<iostream>
void PhysicsWorld::AddBody(const RigidBody& body) {
	bodies.push_back(body);
}
void PhysicsWorld::Step(float dt) {

	for (auto& i : bodies) {

	i.ApplyForce(force);
	i.ApplyForce(gravity * i.mass);
	i.Integrate(dt);
	std::cout << "[POSITION]" << i.position << std::endl;

	}
}