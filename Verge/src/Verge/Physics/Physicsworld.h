#pragma once

#include"RigidBody.h"
#include "Verge/Core/Core.h"
#include<vector>
class VERGE_API  PhysicsWorld {
private:
	std::vector<RigidBody> bodies;
	Vec2 gravity{ 0.0f, -9.81f };
	Vec2 force{ 5.0f, 0.0f };
	float torque = 1.0f;

public:
	void AddBody(const RigidBody& body);
	void Step(float dt);
	void SolveBodyCollision();
	void ResolveCollision(CollisionManifold& m);
	std::vector<RigidBody>& GetBodies() { return bodies; }
};
static void SolveGroundContact(RigidBody& i);
static void SolveGroundPosition(RigidBody& i);