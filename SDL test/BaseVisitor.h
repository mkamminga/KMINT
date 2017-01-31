#pragma once

class CowObject;
class HareObject;
class GraphNode;
class NodeEdge;


class BaseVisitor
{
public:
	virtual void visit(CowObject* cow) = 0;
	virtual void visit(HareObject* hare) = 0;
	virtual void visit(GraphNode* node) = 0;
};

