#include "GraphNode.h"

void GraphNode::addEdges(std::shared_ptr<GraphEdge> edge)
{
	edges.push_back(edge);
}

void GraphNode::addObject(std::shared_ptr<BaseObject> object)
{
	baseObjects.push_back(object);
	object->setX(x);
	object->setY(y);

	object->setNode(shared_from_this());
}

void GraphNode::removeObject(std::shared_ptr<BaseObject> toMatch)
{
	for (auto it = baseObjects.begin(); it != baseObjects.end(); it++)
	{
		auto object = it.operator*();
		if (object == toMatch) {
			baseObjects.erase(it);
			break;
		}
	}
}

const vector<std::shared_ptr<GraphEdge>>& GraphNode::getEdges() const
{
	return edges;
}

const vector<std::shared_ptr<BaseObject>>& GraphNode::getObjects() const
{
	return baseObjects;
}

const int GraphNode::getX() const
{
	return 0;
}

const int GraphNode::getY() const
{
	return 0;
}
