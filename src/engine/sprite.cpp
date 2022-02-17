#include "sprite.h"
#include "cmath"
#include "director.h"

Sprite::Sprite(Node *parent) : Node(parent)
{

}

Sprite::Sprite(Node* parent, sf::Texture &texture) : Node(parent), _texture(texture)
{    
    _texture = texture;

    _sprite = std::make_unique<sf::Sprite>(_texture);
}

Sprite::Sprite(Node* parent, std::string& fileName) : Node(parent)
{
    _texture.loadFromFile(fileName);

    _sprite = std::make_unique<sf::Sprite>(_texture);
}

void Sprite::createSprite(std::string fileName)
{
    _texture.loadFromFile(fileName);

    _sprite = std::make_unique<sf::Sprite>(_texture);
}

void Sprite::draw()
{
    if (_sprite) {
        _sprite->setPosition(_parent->getGlobalPos() + _pos);
        _sprite->setRotation(_parent->getGlobalAngle() + _angle);

        Director::getInstance()->draw(_sprite.get());
    }
}


