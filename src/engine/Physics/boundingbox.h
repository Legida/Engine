#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include "../ref.h"
#include <list>
#include "../node.h"
#include "collidebehavior.h"
#include "physicsbody.h"
#include "physicsbodycreator.h"


class BoundingBox : public Ref
{
public:
    static bool lineIntersection(int x1, int x2, int length1, int length2);

    BoundingBox(Node* parent, Size size, CollideBehavior* behavior);
    BoundingBox(Node* parent, Size size, sf::Vector2f speed, float angle, CollideBehavior* behavior, PhysicsBodyCreator* creator);
    BoundingBox(sf::Vector2f pos, Size size, sf::Vector2f speed, float angle, CollideBehavior* behavior, PhysicsBodyCreator* creator);

    void setSpeed(sf::Vector2f speed);
    void setAngle(float angle);
    void setPosition(int x, int y) override;
    void setPosition(sf::Vector2f pos) override;
    float getAngle();
    sf::Vector2f getSpeed();
    bool isThroughable();
    void setGravitySubjection(bool flag);
    bool getGravitySubjection();

    void move(float dt);
    void update(float dt);
    void collideFunc(BoundingBox* object, float dt, sf::Vector2f result);
    PhysicsBody* getBody();

protected:
    Node* _parent;

    CollideBehavior* _collideBehavior;
    std::unique_ptr<PhysicsBody> _body;

    sf::Vector2f _speed;

    bool _throughable;
    bool _gravitySubjection;
};

#endif // BOUNDINGBOX_H
