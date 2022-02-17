#ifndef PHYSSPRITE_H
#define PHYSSPRITE_H
#include "sprite.h"
#include "Physics/boundingbox.h"
#include <memory>

class PhysSprite : public Sprite
{
public:
    PhysSprite(Node* parent, CollideBehavior* behavior);

    PhysSprite(Node* parent, sf::Texture& texture, CollideBehavior* behavior);

    PhysSprite(Node* parent, std::string fileName, CollideBehavior* behavior);

    BoundingBox* getBody() {return _body.get(); };

    void initBody(CollideBehavior* behavior);
protected:

    std::unique_ptr<BoundingBox> _body;
};

#endif // PHYSSPRITE_H
