#pragma once
#include "TypeDefs.h"
#include <memory>
#include <vector>
#include "GraphNode.h"

class SparseGraph
{
private:
	vector<std::shared_ptr<GraphNode>> nodes;
public:
	void addNode(std::shared_ptr<GraphNode>);
	const vector<std::shared_ptr<GraphNode>>& getNodes() const;
	const double calcDistance(const std::shared_ptr<GraphNode>, const std::shared_ptr<GraphNode>) const;
};