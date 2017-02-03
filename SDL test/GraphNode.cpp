#include "GraphNode.h"
#include <algorithm>

void GraphNode::addEdges(std::shared_ptr<GraphNode> to, double cost)
{
	auto position = std::find_if(edges.begin(), edges.end(), [to](const std::shared_ptr<GraphEdge> edge) {
		return to == edge->getTo();
	});

	if (position == edges.end())
	{
		edges.push_back(std::make_shared<GraphEdge>(this->shared_from_this(), to, cost));

		to->addEdges(this->shared_from_this(), cost);
	}

}

void GraphNode::addObject(std::shared_ptr<BaseObject> object)
{
	baseObjects.push_back(object);
	object->setX(x);
	object->setY(y);
	object->setNode(this->shared_from_this());
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
	return x;
}

const int GraphNode::getY() const
{
	return y;
}

void GraphNode::accept(BaseVisitor * baseVisitor)
{
	baseVisitor->visit(this);
}
