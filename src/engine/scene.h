#ifndef SCENE_H
#define SCENE_H
#include "node.h"
#include "Physics/physicsworld.h"

class Scene : public Node, public PhysicsWorld
{
public:
    Scene() : Node(), PhysicsWorld() {};

    virtual void handleEvents(sf::Event event);
    virtual void update(sf::Time dt);
    void draw() override;    

    float getGlobalAngle() override;
    sf::Vector2f getGlobalPos() override;
};

#endif // SCENE_H
