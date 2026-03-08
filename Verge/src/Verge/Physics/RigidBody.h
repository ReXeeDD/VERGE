#pragma once

#include"Vec2.h"
#include "Verge/Core/Core.h"
enum class ShapeType { Circle, Square };

class VERGE_API  RigidBody
{
public:
    Vec2 position;
    Vec2 velocity;
    Vec2 forceAccum;
    float mass = 0.0f;
    float invMass = 0.0f;
    float restitution = 0.5f;
    float rotation = 0.0f;
    float inertia = 0.0f;
    float invInertia = 0.0f;
    float torqueAccum = 0.0f;
    float angularVelocity = 0.0f;
    

    RigidBody(Vec2 p, Vec2 v, float m);
    virtual ~RigidBody() {}

    void SetMass(float m);
    void ApplyForce(const Vec2& force);
    void IntegrateVelocity(float dt);
    void IntegratePosition(float dt);

    float GetMass() const;
    float GetInvMass() const;
    virtual float GetRadius() const;
    void ApplyTorque(float torque);

    virtual ShapeType GetType() const = 0;
};
class VERGE_API CircleBody : public RigidBody {
public:
    float radius = 0.0f;
    CircleBody(Vec2 p, Vec2 v, float m = 1.0f, float radius = 1.0f);
    float GetRadius() const override;
    ShapeType GetType() const override { return ShapeType::Circle; }

};

struct Sq_size {

    float length;
    float breadth;
};
class VERGE_API SquareBody : public RigidBody {
public:
    float length;
    float breadth;
    SquareBody(Vec2 p, Vec2 v, float m , float l=1.0f, float b=1.0f);
    Sq_size GetSize() const;
    float GetRadius() const override;
    ShapeType GetType() const override { return ShapeType::Square; }

};


struct  CollisionManifold {
    RigidBody* bodyA;
    RigidBody* bodyB;
    float distance = 0;
    Vec2 normal;
    float totalRadius;
    Vec2 Normalized_Normal;


    CollisionManifold(RigidBody* a, RigidBody* b) :bodyA(a), bodyB(b) {
        
        
        totalRadius = bodyA->GetRadius() + bodyB->GetRadius();
    };
    

    bool hit();
    float penetration();
    Vec2 Normal();
};