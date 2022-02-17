#ifndef COLLIDEBEHAVIOR_H
#define COLLIDEBEHAVIOR_H
#include "SFML/Graphics.hpp"

class BoundingBox;

class CollideBehavior
{
public:
    CollideBehavior() {};
    CollideBehavior(BoundingBox* parent) : _parent(parent) {};

    void setParent(BoundingBox* parent) {_parent = parent;};

    virtual void collideFunc(BoundingBox* object, float dt, sf::Vector2f result) = 0;
protected:
    BoundingBox* _parent;
};

class StaticBehavior : public CollideBehavior
{
public:
    StaticBehavior() : CollideBehavior() {};
    StaticBehavior(BoundingBox* parent) : CollideBehavior(parent) {};

    void collideFunc(BoundingBox* object, float dt, sf::Vector2f result) override;
};

class DynamicBehavoir : public CollideBehavior
{
public:
    DynamicBehavoir() : CollideBehavior() {};
    DynamicBehavoir(BoundingBox* parent) : CollideBehavior(parent) {};

    void collideFunc(BoundingBox* object, float dt, sf::Vector2f result) override;
};

#endif // COLLIDEBEHAVIOR_H
