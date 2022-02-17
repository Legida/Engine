#ifndef TESTPHYSICSSCENE_H
#define TESTPHYSICSSCENE_H
#include "engine/scene.h"
#include "engine/sprite.h"
#include <memory>
#include "eventtestsprite.h"
#include <array>

class TestPhysicsScene : public Scene
{
public:
    TestPhysicsScene();

    void update(sf::Time dt) override;
    void handleEvents(sf::Event event) override;

private:

    void keyPressed(sf::Event event);
    void keyReleased(sf::Event event);

    std::unique_ptr<EventTestSprite> _testSprite;
    std::unique_ptr<PhysSprite> _testSprite2;

    sf::Time _posDelTime;

    std::shared_ptr<Sprite> _background;
};

#endif // TESTPHYSICSSCENE_H
