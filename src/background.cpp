#include "background.h"

Background::Background()
{
    _backTexture1 = new sf::Texture();
    _backTexture2 = new sf::Texture();
    _backTexture3 = new sf::Texture();

    _backTexture1->loadFromFile("data/Back1.png");
    _backTexture2->loadFromFile("data/Back2.png");
    _backTexture3->loadFromFile("data/Back3.png");

    _backSrpite = new sf::Sprite(*_backTexture1);

    _clock = 0;
}

void Background::Update()
{
    switch (_clock) {
    case 0:
        _backSrpite->setTexture(*_backTexture1);
        break;
    case 1:
        _backSrpite->setTexture(*_backTexture2);
        break;
    case 2:
        _backSrpite->setTexture(*_backTexture3);
        break;
    }
    _clock = (_clock+1)%3;
}

sf::Sprite& Background::GetSprite()
{
    return *_backSrpite;
}
