#pragma once
#include "BaseVisitor.h"
#include <memory>

class GraphNode;

class BaseObject : std::enable_shared_from_this<BaseObject>
{
protected:
	int x = 0;
	int y = 0;
	std::shared_ptr<GraphNode> currentNode = nullptr;

public:
	BaseObject(int x, int y) : x(x), y(y) {}

	const int getX() const;
	const int getY() const;

	void setX(const int x);
	void setY(const int y);
	void setNode(std::shared_ptr<GraphNode> node);
	virtual void accept(BaseVisitor* baseVisitor) = 0;
};

