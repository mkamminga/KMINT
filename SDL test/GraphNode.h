#pragma once
#include <vector>
#include <memory>
#include "NodeEdge.h"
#include "BaseObject.h"
#include "BaseVisitiable.h"

using std::vector;

class GraphNode : public std::enable_shared_from_this<GraphNode>, public BaseVisitiable
{
private:
	int x;
	int y;
	vector<std::shared_ptr<GraphEdge>> edges;
	vector<std::shared_ptr<BaseObject>> baseObjects;
	vector<std::shared_ptr<Item>> items;
public:
	GraphNode(int x, int y) : x(x), y(y) {}
	virtual ~GraphNode() {}
	void addEdges(std::shared_ptr<GraphNode> to, double cost);
	void  addObject(std::shared_ptr<BaseObject>);
	void  removeObject(std::shared_ptr<BaseObject>);
	void  removeItem(std::shared_ptr<Item>);
	const vector<std::shared_ptr<GraphEdge>>& getEdges() const;
	const vector<std::shared_ptr<BaseObject>>& getObjects() const;
	const vector<std::shared_ptr<Item>>& getItems() const;
	const int getX() const;
	const int getY() const;
	virtual void accept(BaseVisitor*);
};