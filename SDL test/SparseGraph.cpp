#include "SparseGraph.h"

void SparseGraph::addNode(std::shared_ptr<GraphNode> node) {
	nodes.push_back(node);
}

const vector<std::shared_ptr<GraphNode>>& SparseGraph::getNodes() const {
	return nodes;
}

const double SparseGraph::calcDistance(const std::shared_ptr<GraphNode> from, const std::shared_ptr<GraphNode> to) const
{
	return abs(from->getY() - to->getY()) + (from->getX() - to->getX());
}
