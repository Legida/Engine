#ifndef POLYGONBODY_H
#define POLYGONBODY_H
#include "physicsbody.h"
#include "vector"

class PolygonBody : public PhysicsBody
{
public:
    PolygonBody();
    PolygonBody(std::vector<sf::Vector2f>& vertexes);

    void move(sf::Vector2f speed) override;
    void addVertex(sf::Vector2f vertex);
    std::vector<sf::Vector2f> getVertexes();
    std::vector<sf::Vector2f> getNormals();

    sf::Vector2f collisionDetection(PhysicsBody* object2) override;

protected:
    std::vector<sf::Vector2f> _vertexes;
};

#endif // POLYGONBODY_H
