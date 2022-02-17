#ifndef REF_H
#define REF_H
#include "SFML/Graphics.hpp"

struct Size {
    int x;
    int y;
};

class Ref
{
public:
    Ref();
    Ref(float x, float y);
    Ref(sf::Vector2f vec);
    Ref(sf::Vector2f vec, Size size);
    Ref(sf::Vector2f vec, Size size, float angle);

    virtual void setRotation(float angle);
    virtual void Rotate(float angle);
    virtual void setPosition(int x, int y);
    virtual void setPosition(sf::Vector2f pos);
    virtual void setSize(int x, int y);

    virtual float getRotation();
    virtual sf::Vector2f getPosition();
    virtual Size getSize();

protected:
    sf::Vector2f _pos;
    Size _size;
    float _angle;
};

#endif // REF_H
