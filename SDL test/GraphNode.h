#pragma once
#include <vector>
#include <memory>
#include "NodeEdge.h"
#include "BaseObject.h"

using std::vector;

class GraphNode : std::enable_shared_from_this<GraphNode>
{
private:
	int x;
	int y;
	vector<std::shared_ptr<GraphEdge>> edges;
	vector<std::shared_ptr<BaseObject>> baseObjects;
public:
	GraphNode(int x, int y) : x(x), y(y) {}
	virtual ~GraphNode() {}
	void addEdges(std::shared_ptr<GraphEdge>);
	void  addObject(std::shared_ptr<BaseObject>);
	void  removeObject(std::shared_ptr<BaseObject>);
	const vector<std::shared_ptr<GraphEdge>>& getEdges() const;
	const vector<std::shared_ptr<BaseObject>>& getObjects() const;
	const int getX() const;
	const int getY() const;
};