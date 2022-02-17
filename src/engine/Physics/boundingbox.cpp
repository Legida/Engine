#include "boundingbox.h"

bool BoundingBox::lineIntersection(int x1, int x2, int length1, int length2)
{
    return (x1 >= x2 && x1 <= x2 + length2) || (x2 >= x1 && x2 <= x1 + length1);
}

BoundingBox::BoundingBox(Node* parent, Size size, CollideBehavior* behavior) : _speed({0, 0}), _parent(parent), _throughable(false), _collideBehavior(behavior)
  ,_gravitySubjection(true)
{
    _size = size;
    _angle = 0;
    _pos = _parent->getGlobalPos();
    sf::Vector2f size2 = {static_cast<float>(_size.x), static_cast<float>(_size.y)};
    auto temp = new AABBBodyCreator(_pos, size2);
    _body = temp->createBody();
}

BoundingBox::BoundingBox(Node* parent, Size size, sf::Vector2f speed, float angle, CollideBehavior* behavior, PhysicsBodyCreator* creator)
  : _speed(speed), _parent(parent)
  , _throughable(false),  _gravitySubjection(true), _collideBehavior(behavior)
{
    _body = creator->createBody();
    _size = size;
    _angle = angle;
    _pos = _parent->getGlobalPos();
}

BoundingBox::BoundingBox(sf::Vector2f pos, Size size, sf::Vector2f speed, float angle, CollideBehavior* behavior, PhysicsBodyCreator* creator)
  : _speed(speed)
  , _parent(nullptr), _throughable(false), _gravitySubjection(true), _collideBehavior(behavior)
{
    _body = creator->createBody();
    _pos = pos;
}

void BoundingBox::setSpeed(sf::Vector2f speed)
{
    _speed = speed;
}

sf::Vector2f BoundingBox::getSpeed()
{
    return _speed;
}

bool BoundingBox::isThroughable()
{
    return _throughable;
}

void BoundingBox::setGravitySubjection(bool flag)
{
    _gravitySubjection = flag;
}

bool BoundingBox::getGravitySubjection()
{
    return _gravitySubjection;
}

void BoundingBox::move(float dt)
{
    auto newPos = _speed * dt;
    _pos += newPos;
    _body->move(newPos);
}

void BoundingBox::setAngle(float angle)
{
    _angle = angle;
}

void BoundingBox::setPosition(int x, int y)
{
    auto vec = sf::Vector2f(static_cast<float>(x), static_cast<float>(y)) - _pos;
    Ref::setPosition(x ,y);
    _body->move(vec);
}

void BoundingBox::setPosition(sf::Vector2f pos)
{
    setPosition(pos.x, pos.y);
}

float BoundingBox::getAngle()
{
    return _angle;
}

void BoundingBox::update(float dt)
{
    auto nodePos = _parent->getGlobalPos();
    auto dPos = _pos - nodePos;
    _parent->setPosition(_parent->getPosition()+dPos);
}

void BoundingBox::collideFunc(BoundingBox* object, float dt, sf::Vector2f result)
{
    _collideBehavior->collideFunc(object, dt, result);
}

PhysicsBody *BoundingBox::getBody()
{
    return _body.get();
}
