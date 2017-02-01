#include "BaseObject.h"
#include "GraphNode.h"

const int BaseObject::getX() const
{
	return x;
}

const int BaseObject::getY() const 
{
	return y;
}

void BaseObject::setX(const int x)
{
	this->x = x;
}

void BaseObject::setY(const int y)
{
	this->y = y;
}

void BaseObject::setNode(std::shared_ptr<GraphNode> node)
{
	if (currentNode)
	{
		currentNode->removeObject(shared_from_this());
	}

	currentNode = node;
}

std::shared_ptr<GraphNode> BaseObject::getNode()
{
	return currentNode;
}
