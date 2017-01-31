#include "SparseGraph.h"
#include <queue>

void SparseGraph::addNode(std::shared_ptr<GraphNode> node) {
	nodes.push_back(node);
}

const vector<std::shared_ptr<GraphNode>>& SparseGraph::getNodes() const {
	return nodes;
}

ShortestRoute & SparseGraph::shortestPathTo(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> goal)
{
	/*if (lastShortestRoute.start != start || lastShortestRoute.goal != goal)
	{
		//reset
		lastShortestRoute.start = start;
		lastShortestRoute.goal = goal;
		lastShortestRoute.came_from.clear();
		lastShortestRoute.cost_so_far.clear();
		//(re)calculate
		search(start, goal, lastShortestRoute.came_from, lastShortestRoute.cost_so_far);
	}*/

	return lastShortestRoute;
}

const double SparseGraph::calcDistance(const std::shared_ptr<GraphNode> from, const std::shared_ptr<GraphNode> to) const
{
	return abs(from->getY() - to->getY()) + (from->getX() - to->getX());
}

void SparseGraph::search(std::shared_ptr<GraphNode> start, std::shared_ptr<GraphNode> goal, std::unordered_map<std::shared_ptr<GraphNode>, std::shared_ptr<GraphNode>>& came_from, std::unordered_map<std::shared_ptr<GraphNode>, double>& cost_so_far)
{
	std::priority_queue<std::pair<double, std::shared_ptr<GraphNode>>> frontier;
	frontier.push(std::make_pair(0, start));

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		std::pair<double, std::shared_ptr<GraphNode>> pair = frontier.top();
		frontier.pop();

		const std::shared_ptr<GraphNode> current = pair.second;

		if (current == goal) {
			break;
		}

		for (auto next : current->getEdges()) {
			double new_cost = cost_so_far[current] + next->getCost();

			double oldCosts = 0;
			if (cost_so_far.find(next->getTo()) != cost_so_far.end()) // any parent linked to this node?
			{
				oldCosts = cost_so_far[next->getTo()];
			}

			if (!cost_so_far.count(next->getTo()) || new_cost < oldCosts) {
				cost_so_far[next->getTo()] = new_cost;
				double priority = new_cost + calcDistance(current, next->getTo());
				frontier.push(std::make_pair(priority, next->getTo())); // push priority as real costs + heuristic costs
				came_from[next->getTo()] = current;
			}
		}
	}
}