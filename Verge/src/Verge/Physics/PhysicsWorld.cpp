#include "Physicsworld.h"
#include<iostream>
void PhysicsWorld::AddBody(const RigidBody& body) {
	bodies.push_back(body);
}
void PhysicsWorld::Step(float dt) {

	for (auto& i : bodies) {

	i.ApplyForce(gravity * i.mass);
	
	i.Integrate(dt);
    if (i.position.y - i.radius <= 0.0f)
    {
        Vec2 normal(0, 1);

        Vec2 contactPoint = i.position - Vec2(0, i.radius);
        Vec2 r = contactPoint - i.position;

        Vec2 vPoint = i.velocity + Vec2(-r.y, r.x) * i.angularVelocity;

        float velAlongNormal = vPoint.Dot(normal);

        if (velAlongNormal < 0)
        {
            float e = i.restitution;

            float rn = r.Cross(normal);
            float denom = i.invMass + (rn * rn) * i.invInertia;

            float j = -(1 + e) * velAlongNormal;
            j /= denom;

            Vec2 impulse = normal * j;

            i.velocity += impulse * i.invMass;
            i.angularVelocity += r.Cross(impulse) * i.invInertia;
        }

        // Position correction
        i.position.y = i.radius;
    }
	std::cout << "[POSITION]" << i.position << std::endl;

	}
}