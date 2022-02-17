#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "scene.h"
#include <memory>

class Director
{
public:
    static Director* getInstance();

    void gameInit();
    void gameLoop();
    void draw(sf::Sprite* sprite);

    void changeScene(Scene* scene);
    Scene* getActiveScene() { return _scene; };

    sf::View* getDefaultCamera();

    ~Director();
private:
    static Director* _instance;

    Scene* _scene;
    sf::Clock _gameClock;
    std::unique_ptr<sf::View> _defaultCamera;

    std::shared_ptr<sf::RenderWindow> _window;

    Director();
};

#endif // DIRECTOR_H
