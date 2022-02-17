#include "ref.h"
#include <cmath>

Ref::Ref()
{
    _pos = {0, 0};
    _size = {0, 0};
    _angle = 0;
}

Ref::Ref(float x, float y)
{
    Ref();
    _pos = {x, y};
}

Ref::Ref(sf::Vector2f vec)
{
    Ref();
    _pos = vec;
}

Ref::Ref(sf::Vector2f vec, Size size)
{
    Ref();
    _pos = vec;
    _size = size;
}

Ref::Ref(sf::Vector2f vec, Size size, float angle)
{
    _pos = vec;
    _size = size;
    _angle = angle;
}

void Ref::setRotation(float angle)
{
    _angle = angle;
    _angle = fmod(angle, 360);
}

void Ref::Rotate(float angle)
{
    _angle += angle;
    _angle = fmod(_angle, 360);
}

void Ref::setPosition(int x, int y)
{
    _pos = sf::Vector2f(x, y);
}

void Ref::setPosition(sf::Vector2f pos)
{
    setPosition(pos.x, pos.y);
}

void Ref::setSize(int x, int y)
{
    _size = {x, y};
}

float Ref::getRotation()
{
    return _angle;
}

sf::Vector2f Ref::getPosition()
{
    return _pos;
}

Size Ref::getSize()
{
    return _size;
}

