#include "RigidBody.h"
#include"Vec2.h"

RigidBody::RigidBody(Vec2 p, Vec2 v, float m=1.0f):position(p),velocity(v),mass(m){}

void RigidBody::ApplyForce(const Vec2& force) {
	forceAccum += force;
}
void RigidBody::Integrate(float dt) {
    Vec2 acceleration = forceAccum / mass;
    velocity += acceleration * dt;
    position += velocity * dt;
    

    forceAccum = Vec2::Zero();
}