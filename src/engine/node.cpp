#include "node.h"

Node::Node() : Ref()
{
    _parent = nullptr;
}

Node::Node(Node* parent) : Node()
{
    //setParent(parent);
    parent->addChild(this);
}

void Node::addChild(Node* child)
{
    if (child->getParent() != nullptr)
    {
        child->getParent()->removeChild(child);
    }
    _childList.push_back(child);

    child->setParent(this);
}

void Node::removeChild(Node* child)
{
    child->setParent(nullptr);
    _childList.remove(child);
}

Node* Node::getParent()
{
    return _parent;
}

void Node::setParent(Node* parent)
{
    _parent = parent;
}

void Node::handleEvents(sf::Event event)
{
    for(auto i : _childList)
    {
        i->handleEvents(event);
    }
}

void Node::update(sf::Time dt)
{
    for(auto i : _childList)
    {
        i->update(dt);
    }
}

void Node::draw()
{
    for(auto i : _childList)
    {
        i->draw();
    }
}

sf::Vector2f Node::getGlobalPos()
{
    auto pos = _parent->getGlobalPos();
    pos += _pos;
    return pos;
}

float Node::getGlobalAngle()
{
    auto angle = _parent->getGlobalAngle();
    angle += angle;
    return angle;
}
