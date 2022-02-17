#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background
{
private:
    int _clock;
    sf::Texture* _backTexture1;
    sf::Texture* _backTexture2;
    sf::Texture* _backTexture3;
    sf::Sprite* _backSrpite;
public:
    Background();
    void Update();
    sf::Sprite& GetSprite();
};

#endif // BACKGROUND_H
