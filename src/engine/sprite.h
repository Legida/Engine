#ifndef SPRITE_H
#define SPRITE_H
#include "node.h"
#include <memory>

class Sprite : public Node
{
public:
    Sprite(Node* parent);

    Sprite(Node* parent, sf::Texture& texture);

    Sprite(Node* parent, std::string& fileName);

    void createSprite(std::string fileName);

    //dont need now
    //void handleEvents(sf::Event event) override;
    //void update(sf::Time dt) override;

    void draw() override;

protected:
    std::unique_ptr<sf::Sprite> _sprite;

    sf::Texture _texture;
};

#endif // SPRITE_H
