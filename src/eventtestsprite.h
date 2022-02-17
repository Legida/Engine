#ifndef EVENTTESTSPRITE_H
#define EVENTTESTSPRITE_H
#include "engine/physsprite.h"

class EventTestSprite : public PhysSprite
{
public:
    EventTestSprite(Node* parent);

    void handleEvents(sf::Event event) override;
    void update(sf::Time dt) override;

private:

    void keyPressed(sf::Event event);
    void keyReleased(sf::Event event);

    sf::Vector2f _moveSpeed;
};

#endif // EVENTTESTSPRITE_H
