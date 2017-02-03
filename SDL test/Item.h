#pragma once
#include "GraphNode.h"

class Item : std::enable_shared_from_this<Item>
{
private:
	std::shared_ptr<GraphNode> node = nullptr;
public:
	Item(std::shared_ptr<GraphNode> node) : node(node) {}
	void removeFromNode();
	virtual void execute() = 0;
};

