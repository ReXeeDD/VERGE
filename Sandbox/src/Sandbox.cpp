#include "Verge.h"
#include "Verge/Physics/PhysicsWorld.h"
#include "Verge/Physics/RigidBody.h"
#include "Verge/Physics/Vec2.h"
#include <SFML/Graphics.hpp>

class Sandbox : public Verge::Application {
private:
    float pixelsPerMeter = 50.0f; // Scale: 1 physics unit = 50 pixels

public:
    void Run() override {
        // 1. Setup Window
        sf::RenderWindow window(sf::VideoMode(800, 600), "Verge Engine | Sandbox");
        window.setFramerateLimit(60);

        // 2. Setup Physics World
        PhysicsWorld world;
        world.AddBody(new CircleBody(Vec2(5.21f, 10.0f), Vec2(0, 0), 10.0f, 1.0f)); // Falling ball
        world.AddBody(new CircleBody(Vec2(5.2f, 2.0f), Vec2(0, 5.0f), 5.0f, 0.8f)); // Rising ball

        const float dt = 1.0f / 60.0f;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) window.close();
            }

            // 3. Step Physics
            world.Step(dt);

            // 4. Render
            window.clear(sf::Color(30, 30, 30)); // Dark grey background

            // Draw Ground Line at y=0
            sf::Vertex ground[] = {
                sf::Vertex(sf::Vector2f(0, 600)),
                sf::Vertex(sf::Vector2f(800, 600))
            };
            window.draw(ground, 2, sf::Lines);

            // Draw Bodies
            // Note: You need a GetBodies() function in PhysicsWorld to make this work!
            for (auto body : world.GetBodies()) {
                // Access radius via the pointer
                sf::CircleShape shape(body->GetRadius() * pixelsPerMeter);
                shape.setOrigin(body->GetRadius() * pixelsPerMeter, body->GetRadius() * pixelsPerMeter);

                // Access position via the pointer
                float screenX = body->position.x * pixelsPerMeter;
                float screenY = 600.0f - (body->position.y * pixelsPerMeter);

                shape.setPosition(screenX, screenY);
                shape.setFillColor(sf::Color::Cyan);
                window.draw(shape);
            }

            window.display();
        }
    }
};

Verge::Application* Verge::CreateApplication() {
    return new Sandbox();
}