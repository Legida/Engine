#include "polygonbody.h"

PolygonBody::PolygonBody() : PhysicsBody()
{
    _type = type::polygon;
}

PolygonBody::PolygonBody(std::vector<sf::Vector2f>& vertexes) : PhysicsBody(), _vertexes(vertexes)
{

}

void PolygonBody::move(sf::Vector2f speed)
{
    for(auto i : _vertexes)
    {
        i += speed;
    }
}

void PolygonBody::addVertex(sf::Vector2f vertex)
{
    _vertexes.push_back(vertex);
}

std::vector<sf::Vector2f> PolygonBody::getVertexes()
{
    return _vertexes;
}

std::vector<sf::Vector2f> PolygonBody::getNormals()
{
    std::vector<sf::Vector2f> normals;
    for(int i = 0; i < _vertexes.size() - 1; i++)
    {
        if(i < _vertexes.size() - 1)
        {
            normals.push_back({_vertexes[i+1].x - _vertexes[i].x, -(_vertexes[i+1].y - _vertexes[i].y)});
        }
    }
    normals.push_back({_vertexes[_vertexes.size() - 1].x - _vertexes[0].x, -(_vertexes[_vertexes.size() - 1].y - _vertexes[0].y)});

    return normals;
}

sf::Vector2f PolygonBody::collisionDetection(PhysicsBody *object2)
{
    switch (object2->getType()) {
    case type::AABB:
        return AABBPolyCollision(object2, this);
    case type::circle:
        return CirclePolyCollision(object2, this);
    case type::polygon:
        return PolyCollision(this, object2);
    }
    return sf::Vector2f(0, 0);
}






