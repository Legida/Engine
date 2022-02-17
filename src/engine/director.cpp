#include "director.h"

Director* Director::_instance = nullptr;

Director::Director()
{

}

Director* Director::getInstance() {
    if (_instance == nullptr)
    {
        _instance = new Director;
    }

    return _instance;
}

void Director::gameInit()
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "SFML works!");
    _window->setKeyRepeatEnabled(false);

    _defaultCamera = std::make_unique<sf::View>(_window->getDefaultView());
    _window->setView(*_defaultCamera);
}

void Director::gameLoop()
{
    while (_window->isOpen())
    {
        auto frameClock = _gameClock;

        _gameClock.restart();

        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window->close();
            }

            _scene->handleEvents(event);

        }

        _scene->update(frameClock.getElapsedTime());

        _window->setView(*_defaultCamera);

        _window->clear();

        _scene->draw();

        _window->display();
    }
}

void Director::draw(sf::Sprite *sprite)
{
    _window->draw(*sprite);
}

void Director::changeScene(Scene* scene)
{
    _scene = scene;
}

sf::View *Director::getDefaultCamera()
{
    return _defaultCamera.get();
}


