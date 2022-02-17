    #include "eventtestsprite.h"
#include "engine/director.h"

EventTestSprite::EventTestSprite(Node* parent) : PhysSprite(parent, std::string("data/test.png"), new DynamicBehavoir())
{
    _body->setGravitySubjection(false);
}

void EventTestSprite::handleEvents(sf::Event event)
{
    switch (event.type) {
    case sf::Event::KeyPressed:
        keyPressed(event);
        break;
    case sf::Event::KeyReleased:
        keyReleased(event);
        break;
    default:
        break;
    }
}

void EventTestSprite::update(sf::Time dt)
{
    auto newSpeed = sf::Vector2f(_moveSpeed.x, _body->getSpeed().y);
    if (_moveSpeed.y != 0)
    {
        newSpeed.y = _moveSpeed.y;
    }
    _body->setSpeed(newSpeed);
    PhysSprite::update(dt);
    auto pos = getPosition();
    _pos = pos;
    Director::getInstance()->getDefaultCamera()->setCenter(getPosition());
}

void EventTestSprite::keyPressed(sf::Event event)
{
    switch(event.key.code) {
    case sf::Keyboard::S:
        _moveSpeed += {0, 32*20};
        break;
    case sf::Keyboard::W:
        _moveSpeed += {0, -32*20};
        break;
    case sf::Keyboard::A:
        _moveSpeed += {-32*20, 0};
        break;
    case sf::Keyboard::D:
        _moveSpeed += {32*20, 0};
        break;
    default:
        break;
    }
}

void EventTestSprite::keyReleased(sf::Event event)
{
    switch(event.key.code) {
    case sf::Keyboard::S:
        _moveSpeed -= {0, 32*20};
        break;
    case sf::Keyboard::W:
        _moveSpeed -= {0, -32*20};
        break;
    case sf::Keyboard::A:
        _moveSpeed -= {-32*20, 0};
        break;
    case sf::Keyboard::D:
        _moveSpeed -= {32*20, 0};
        break;
    default:
        break;
    }
}
