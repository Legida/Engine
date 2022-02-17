#ifndef AABBBODY_H
#define AABBBODY_H
#include "physicsbody.h"

class AABBBody : public PhysicsBody
{
public:
    AABBBody(sf::Vector2f anchor, sf::Vector2f size);

    void move(sf::Vector2f speed) override;
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getAnchor();
    sf::Vector2f getSize();

    sf::Vector2f collisionDetection(PhysicsBody* object2) override;
protected:
    sf::Vector2f _anchor;
    sf::Vector2f _size;
};

#endif // AABBBODY_H
