#include "Game.h"
#include "GraphNode.h"
#include "NodeEdge.h"

void Game::start()
{
	auto firstNode = std::make_shared<GraphNode>(50, 20);
	auto secondNode = std::make_shared<GraphNode>(300, 140);
	auto thirdNode = std::make_shared<GraphNode>(600, 190);
	auto fourthNode = std::make_shared<GraphNode>(630, 449);
	auto fifthNode = std::make_shared<GraphNode>(200, 589);

	firstNode->addEdges(secondNode, 30);
	secondNode->addEdges(thirdNode, 30);
	secondNode->addEdges(fifthNode, 70);
	thirdNode->addEdges(firstNode, 50);
	fourthNode->addEdges(fifthNode, 30);
	fourthNode->addEdges(thirdNode, 30);
	firstNode->addEdges(fifthNode, 90);

	graph->addNode(firstNode);
	graph->addNode(secondNode);
	graph->addNode(thirdNode);
	graph->addNode(fourthNode);
	graph->addNode(fifthNode);
	
	secondNode->addObject(cow);
	fifthNode->addObject(hare);

	auto nodes = graph->getNodes();
	for (auto node : nodes)
	{
		objects.push_back(node);
	}
	
	objects.push_back(cow);
	objects.push_back(hare);
}

std::shared_ptr<CowObject> Game::getCow()
{
	return cow;
}

std::shared_ptr<HareObject> Game::getHare()
{
	return hare;
}

std::shared_ptr<SparseGraph> Game::getGraph()
{
	return graph;
}

std::vector<std::shared_ptr<BaseVisitiable>>& Game::gameObjects()
{
	return objects;
}
