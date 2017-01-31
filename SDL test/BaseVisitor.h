#pragma once

class CowObject;
class GraphNode;
class NodeEdge;

class BaseVisitor
{
public:
	virtual void visit(CowObject* cow) = 0;
	virtual void visit(GraphNode* node) = 0;
	virtual void visit(NodeEdge* edge) = 0;
};

