#include "mainscene.h"
#include "engine/director.h"

MainScene::MainScene() : Scene()
{
    setPhysicsFPS(180);
    setGravity(64.f * 36);

    _testSprite = std::make_unique<EventTestSprite>(this);
    _testSprite->getBody()->setPosition(_testSprite->getBody()->getPosition() + sf::Vector2f(128, 0));

    auto a = std::string("data/fonk.png");

    _background = std::make_shared<Sprite>(this, a);

    addChild(_background.get());

    for(int i = 0; i < 27; i++)
    {
        _testList.push_back(std::make_unique<PhysSprite>(this, std::string("data/test.png"), new StaticBehavior()));
        auto& f = _testList.back();
        addChild(f.get());
        if (i < 10)
        {
            f->getBody()->setPosition(f->getPosition() + sf::Vector2f(0 + i*64, 500));
        }
        else if (i < 20)
        {
            f->getBody()->setPosition(f->getPosition() + sf::Vector2f(640 + (i-10)*192, 500));
        }
        else
        {
            f->getBody()->setPosition(f->getPosition() + sf::Vector2f(0, 500 - (i-20)*64));
        }

        f->getBody()->setGravitySubjection(false);
    }

    _posDelTime = sf::milliseconds(0);

    addChild(_testSprite.get());

    _testSprite->getBody()->setGravitySubjection(true);
}

void MainScene::update(sf::Time dt)
{
    Scene::update(dt);
}

void MainScene::handleEvents(sf::Event event)
{
    _testSprite->handleEvents(event);
}

void MainScene::keyPressed(sf::Event event)
{
    _testSprite->handleEvents(event);
}

void MainScene::keyReleased(sf::Event event)
{

}


