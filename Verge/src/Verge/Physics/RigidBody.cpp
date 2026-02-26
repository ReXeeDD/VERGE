#include "RigidBody.h"
#include"Vec2.h"

RigidBody::RigidBody(Vec2 p, Vec2 v, Vec2 f):position(p),velocity(v),forceAccum(f){}

void RigidBody::ApplyForce(const Vec2& force) {
	forceAccum += force;
}
void RigidBody::Integrate(float dt) {
    Vec2 acceleration = forceAccum / mass;
    velocity += acceleration * dt;
    position += velocity * dt;

    forceAccum = Vec2::Zero();
}