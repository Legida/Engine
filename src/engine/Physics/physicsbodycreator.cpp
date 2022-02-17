#include "physicsbodycreator.h"
#include "circlebody.h"
#include "aabbbody.h"
#include "polygonbody.h"

std::unique_ptr<PhysicsBody> CircleBodyCreator::createBody()
{
    return std::make_unique<CircleBody>(_radius, _center);
}
std::unique_ptr<PhysicsBody> AABBBodyCreator::createBody()
{
    return std::make_unique<AABBBody>(_anchor, _size);
}

std::unique_ptr<PhysicsBody> PolygonBodyCreator::createBody()
{
    return std::make_unique<PolygonBody>(_vertexes);
}
