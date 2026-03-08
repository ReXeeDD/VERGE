#include "RigidBody.h"
#include"Vec2.h"

RigidBody::RigidBody(Vec2 p, Vec2 v, float m=1.0f):position(p),velocity(v),mass(m){
    invMass= invMass = (mass > 0) ? 1.0f / mass : 0.0f;
    
}


void RigidBody::ApplyForce(const Vec2& force) {
	forceAccum += force;
}
void RigidBody::IntegrateVelocity(float dt) {
    // Linear
    Vec2 acceleration = forceAccum * invMass;
    velocity += acceleration * dt;
    
    // Angular
    float angularAcc = torqueAccum * invInertia;
    angularVelocity += angularAcc * dt;

    forceAccum = Vec2::Zero();
    torqueAccum = 0.0f;
}
void RigidBody::IntegratePosition(float dt) {
    position += velocity * dt;
    rotation += angularVelocity * dt;


}


void RigidBody::SetMass(float m) {
    mass = m;
    invMass = (mass > 0.0f) ? 1.0f / mass : 0.0f;
}
float RigidBody::GetMass() const { return mass; }
float RigidBody::GetInvMass() const { return invMass; }
float RigidBody::GetRadius() const { return 0.0f; }

void RigidBody::ApplyTorque(float torque)
{
    torqueAccum += torque;
}
bool CollisionManifold::hit() {
    normal = bodyA->position - bodyB->position;
    distance = normal.Length();
    if (distance < 0.0001f) Normalized_Normal = Vec2(0, 1); 
    else Normalized_Normal = normal.Normalized();
    if (distance < totalRadius) {
        return true;
    }
    return false;

}
float CollisionManifold::penetration() {
    return { totalRadius - distance };

}
Vec2 CollisionManifold::Normal() {
    
        return Normalized_Normal;

    
}

CircleBody::CircleBody(Vec2 p, Vec2 v, float m , float radius):RigidBody(p, v, m), radius(radius) {
    invMass = invMass = (mass > 0) ? 1.0f / mass : 0.0f;
    inertia = 0.5f * mass * radius * radius;
    invInertia = (inertia > 0) ? 1.0f / inertia : 0.0f;
}
float  CircleBody::GetRadius() const  { return radius; }


SquareBody::SquareBody(Vec2 p, Vec2 v, float m , float l,float b):RigidBody(p, v, m), length(l),breadth(b) {
    invMass = invMass = (mass > 0) ? 1.0f / mass : 0.0f;
    inertia = (1.0f / 12.0f) * mass * (length * length + breadth * breadth);
    invInertia = (inertia > 0) ? 1.0f / inertia : 0.0f;
}
float SquareBody::GetRadius() const  {
    // Pythagorean theorem to find distance to corner
    return 0.5f * std::sqrt(length * length + breadth * breadth);
}
Sq_size  SquareBody::GetSize() const { return {length,breadth}; }