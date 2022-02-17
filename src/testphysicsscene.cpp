#include "testphysicsscene.h"
#include "engine/director.h"

TestPhysicsScene::TestPhysicsScene() : Scene()
{
    setPhysicsFPS(180);
    setGravity(64.f * 36);

    _testSprite = std::make_unique<EventTestSprite>(this);
    _testSprite->getBody()->setPosition(_testSprite->getBody()->getPosition() + sf::Vector2f(0, 0));
    _testSprite2 = std::make_unique<PhysSprite>(this, std::string("data/test.png"), new StaticBehavior());

    _testSprite2->getBody()->setPosition(0, 500);

    auto a = std::string("data/fonk.png");

    _background = std::make_shared<Sprite>(this, a);

    addChild(_background.get());

    addChild(_testSprite2.get());

    addChild(_testSprite.get());

    _testSprite2->getBody()->setGravitySubjection(false);
    _testSprite->getBody()->setGravitySubjection(false);
}

void TestPhysicsScene::update(sf::Time dt)
{
    Scene::update(dt);
}

void TestPhysicsScene::handleEvents(sf::Event event)
{
    _testSprite->handleEvents(event);
}

void TestPhysicsScene::keyPressed(sf::Event event)
{

}

void TestPhysicsScene::keyReleased(sf::Event event)
{

}


