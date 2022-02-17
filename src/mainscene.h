#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "engine/scene.h"
#include "engine/sprite.h"
#include <memory>
#include "eventtestsprite.h"
#include <array>
class MainScene : public Scene
{
public:
    MainScene();

    void update(sf::Time dt) override;
    void handleEvents(sf::Event event) override;

private:

    void keyPressed(sf::Event event);
    void keyReleased(sf::Event event);

    std::unique_ptr<EventTestSprite> _testSprite;
    std::array<std::unique_ptr<PhysSprite>, 10> _testSprites;
    std::list<std::unique_ptr<PhysSprite>> _testList;

    sf::Time _posDelTime;

    std::shared_ptr<Sprite> _background;

};

#endif // MAINSCENE_H
