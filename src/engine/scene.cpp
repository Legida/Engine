#include "scene.h"

void Scene::handleEvents(sf::Event event)
{
    for(auto i : _childList)
    {
        i->handleEvents(event);
    }
}

void Scene::update(sf::Time dt)
{
    PhysicsWorld::update(dt);

    for(auto i : _childList)
    {
        i->update(dt);
    }
}

void Scene::draw()
{
    for(auto i : _childList)
    {
        i->draw();
    }
}

sf::Vector2f Scene::getGlobalPos()
{
    return _pos;
}

float Scene::getGlobalAngle()
{
    return _angle;
}
