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
	if (i.position.y <= 0) {

		i.position.y = 0;
		i.velocity.y = -i.velocity.y *i.restitution;
	}
	std::cout << "[POSITION]" << i.position << std::endl;

	}
}