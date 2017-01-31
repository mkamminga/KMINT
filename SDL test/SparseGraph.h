#pragma once
#include "TypeDefs.h"
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include "GraphNode.h"

struct ShortestRoute
{
	std::shared_ptr<GraphNode> start;
	std::shared_ptr<GraphNode> goal;
	std::unordered_map<std::shared_ptr<GraphNode>, std::shared_ptr<GraphNode>> came_from;
	std::unordered_map<std::shared_ptr<GraphNode>, double> cost_so_far;
};

class SparseGraph
{
private:
	vector<std::shared_ptr<GraphNode>> nodes;
	ShortestRoute lastShortestRoute;
public:
	SparseGraph() {}
	void addNode(std::shared_ptr<GraphNode>);
	const vector<std::shared_ptr<GraphNode>>& getNodes() const;
	ShortestRoute& shortestPathTo(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> goal);
	void search(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> goal, std::unordered_map<std::shared_ptr<GraphNode>, std::shared_ptr<GraphNode>>& came_from, std::unordered_map<std::shared_ptr<GraphNode>, double>& cost_so_far);
	const double calcDistance(const std::shared_ptr<GraphNode>, const std::shared_ptr<GraphNode>) const;
};




