#pragma once

#include"RigidBody.h"
#include<vector>
class PhysicsWorld {
private:
	std::vector<RigidBody> bodies;
	Vec2 gravity{ 0.0f, -9.81f };
	Vec2 force{ 5.0f, 5.0f };

public:
	void AddBody(const RigidBody& body);
	void Step(float dt);
};