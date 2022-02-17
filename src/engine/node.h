#ifndef NODE_H
#define NODE_H
#include "ref.h"
#include <list>

class Node : public Ref
{
public:
    Node();
    Node(Node* parent);

    void addChild(Node* child);
    void removeChild(Node* child);
    void setParent(Node* parent);
    Node* getParent();

    virtual void handleEvents(sf::Event event);
    virtual void update(sf::Time dt);
    virtual void draw();

    virtual sf::Vector2f getGlobalPos();
    virtual float getGlobalAngle();

protected:
     //dont need in public but need for scene class

    std::list<Node*> _childList;
    Node* _parent;
};

#endif // NODE_H
