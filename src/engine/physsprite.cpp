#include "physsprite.h"
#include "director.h"

PhysSprite::PhysSprite(Node *parent, CollideBehavior* behavior) : Sprite(parent)
{
    initBody(behavior);
}

PhysSprite::PhysSprite(Node *parent, sf::Texture &texture, CollideBehavior* behavior) : Sprite(parent, texture)
{
    initBody(behavior);
}

PhysSprite::PhysSprite(Node *parent, std::string fileName, CollideBehavior* behavior) : Sprite(parent, fileName)
{
    initBody(behavior);
}

void PhysSprite::initBody(CollideBehavior* behavior)
{
    Size size = {static_cast<int>(_texture.getSize().x), static_cast<int>(_texture.getSize().y)};
    _body = std::make_unique<BoundingBox>(this, size, behavior);
    behavior->setParent(_body.get());
    dynamic_cast<Scene*>(_parent)->addBoundingBox(_body.get());
}


