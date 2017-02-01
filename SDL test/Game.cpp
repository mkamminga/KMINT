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
	auto sifthNode = std::make_shared<GraphNode>(800, 689);
	auto zeventhNode = std::make_shared<GraphNode>(800, 221);
	auto eithNode = std::make_shared<GraphNode>(700, 321);


	firstNode->addEdges(secondNode, 0);
	secondNode->addEdges(thirdNode, 0);
	secondNode->addEdges(fifthNode, 0);
	thirdNode->addEdges(firstNode, 0);
	fourthNode->addEdges(fifthNode, 0);
	fourthNode->addEdges(thirdNode, 0);
	firstNode->addEdges(fifthNode, 0);
	sifthNode->addEdges(fifthNode, 0);
	zeventhNode->addEdges(sifthNode, 0);
	eithNode->addEdges(zeventhNode, 0);
	eithNode->addEdges(thirdNode, 0);

	graph->addNode(firstNode);
	graph->addNode(secondNode);
	graph->addNode(thirdNode);
	graph->addNode(fourthNode);
	graph->addNode(fifthNode);
	graph->addNode(sifthNode);
	graph->addNode(zeventhNode);
	
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
