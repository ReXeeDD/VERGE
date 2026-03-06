#include "Physicsworld.h"
#include<iostream>
#include<algorithm>
void PhysicsWorld::AddBody(const RigidBody& body) {
	bodies.push_back(body);
}
void PhysicsWorld::Step(float dt) {
    const int iterations = 12;
    const int positionIterations = 4;

    for (auto& i : bodies) {

        i.ApplyForce(gravity * i.mass);
        i.IntegrateVelocity(dt);
    }

    for (int k = 0; k < iterations; ++k) {
        for (auto& i : bodies) {
            SolveGroundContact(i);
        }
    }
    for (auto& i : bodies) {
        i.IntegratePosition(dt);
	    std::cout << "[POSITION]" << i.position << std::endl;
    }
    for (int k = 0; k < positionIterations; ++k) {
        for (auto& i : bodies) {
            SolveGroundPosition(i);
        }
    }	

    
}

static void SolveGroundContact(RigidBody& i) {
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

            Vec2 vPointAfter = i.velocity + Vec2(-r.y, r.x) * i.angularVelocity;
            Vec2 vRel = vPointAfter;

            Vec2 tangent = vRel - normal * vRel.Dot(normal);

            if (tangent.LengthSquared() > 0.0001f)
            {
                tangent.Normalize();

                float vt = vRel.Dot(tangent);
                float rt = r.Cross(tangent);

                float denomTangent = i.invMass + (rt * rt) * i.invInertia;

                float jt = -vt / denomTangent;

                float mu = 0.5f;
                float maxFriction = std::abs(j) * mu;

                jt = std::clamp(jt, -maxFriction, maxFriction);

                Vec2 frictionImpulse = tangent * jt;

                i.velocity += frictionImpulse * i.invMass;
                i.angularVelocity += r.Cross(frictionImpulse) * i.invInertia;
            }

        }

    }
}

static void SolveGroundPosition(RigidBody& i)
{
    float penetration = i.radius - i.position.y;

    if (penetration > 0.0f)
    {
        float correctionPercent = 0.8f;   
        float slop = 0.01f;               

        float correction = std::max(penetration - slop, 0.0f);
        correction *= correctionPercent;

        i.position.y += correction;
    }
}

void PhysicsWorld::SolveBodyCollision(){

    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            CollisionManifold manifold{ bodies[i],bodies[j] };
            if (manifold.hit()) {
                std::cout << "HIT!" << std::endl;
                ResolveCollision(manifold);
            }

        }
    }

}
void PhysicsWorld::ResolveCollision(CollisionManifold& m) {
    RigidBody* a = m.bodyA;
    RigidBody* b = m.bodyB;

    Vec2 relVel = a->velocity - b->velocity;

    float velAlongNormal = relVel.Dot(m.Normal());

    if (velAlongNormal > 0) return;

    float e = a->restitution * b->restitution;

    float j = -(1 + e) * velAlongNormal;
    j /= (a->invMass + b->invMass);

    Vec2 impulse = m.Normal() * j;

    a->velocity += impulse * a->invMass;
    b->velocity -= impulse * b->invMass;



    const float percent = 0.8f; 
    const float slop = 0.01f;   
    float penetration = m.penetration();
    Vec2 correction = m.Normal() * (std::max(penetration - slop, 0.0f) / (a->invMass + b->invMass) * percent);

    a->position += correction * a->invMass;
    b->position -= correction * b->invMass;
}