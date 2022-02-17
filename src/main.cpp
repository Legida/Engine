#include <SFML/Graphics.hpp>
#include "background.h"
#include "engine/director.h"
#include "mainscene.h"
#include "testphysicsscene.h"

int main()
{
        auto gameDirector = Director::getInstance();

        auto mainScene = std::make_shared<MainScene>();

        gameDirector->changeScene(mainScene.get());

        gameDirector->gameInit();

        gameDirector->gameLoop();

        return 0;
}
