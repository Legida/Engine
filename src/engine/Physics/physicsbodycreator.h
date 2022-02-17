#ifndef PHYSICSBODYCREATOR_H
#define PHYSICSBODYCREATOR_H
#include <memory>
#include "physicsbody.h"

class PhysicsBodyCreator
{
public:
    PhysicsBodyCreator() {};

    virtual std::unique_ptr<PhysicsBody> createBody() = 0;
};

class CircleBodyCreator : public PhysicsBodyCreator
{
public:
    CircleBodyCreator(float& radius, sf::Vector2f& center) : PhysicsBodyCreator(), _radius(radius), _center(center) {};

    std::unique_ptr<PhysicsBody> createBody() override;
private:
    float _radius;
    sf::Vector2f _center;
};

class AABBBodyCreator : public PhysicsBodyCreator
{
public:
    AABBBodyCreator(sf::Vector2f& anchor, sf::Vector2f& size) : PhysicsBodyCreator(), _anchor(anchor), _size(size) {};

    std::unique_ptr<PhysicsBody> createBody() override;
private:
    sf::Vector2f _anchor;
    sf::Vector2f _size;
};

class PolygonBodyCreator : public PhysicsBodyCreator
{
public:
    PolygonBodyCreator(std::vector<sf::Vector2f>& vertexes) : PhysicsBodyCreator(), _vertexes(vertexes) {};

    std::unique_ptr<PhysicsBody> createBody() override;
private:
    std::vector<sf::Vector2f> _vertexes;
};

#endif // PHYSICSBODYCREATOR_H
