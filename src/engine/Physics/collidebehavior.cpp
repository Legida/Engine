#include "collidebehavior.h"
#include "boundingbox.h"
#include <cmath>
#include <iostream>

void StaticBehavior::collideFunc(BoundingBox *object, float dt, sf::Vector2f result)
{

}

void DynamicBehavoir::collideFunc(BoundingBox *object, float dt, sf::Vector2f result)
{
    auto norm = [](sf::Vector2f& vector)
    {
        float d = hypot(vector.x, vector.y);
        float norm_x = vector.x /d;
        float norm_y = vector.y /d;
        vector = {norm_x, norm_y};
    };

    sf::Vector2f collision = result;
    norm(collision);
    collision = {-collision.y, collision.x};

    sf::Vector2f normSp = _parent->getSpeed();
    float product = (normSp.x*collision.x + normSp.y*collision.y)/sqrt(pow(collision.x, 2) + pow(collision.y, 2));
    sf::Vector2f dVec = {collision.x * product, collision.y * product};

    _parent->setPosition(_parent->getPosition() - result);
    sf::Vector2f sp = {dVec.x, dVec.y};
    _parent->setSpeed(sp);
}
