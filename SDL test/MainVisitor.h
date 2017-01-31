#pragma once

#include "BaseVisitor.h"

class MainVisitor : BaseVisitor
{
public:
	virtual void visit(CowObject* cow);
	virtual void visit(GraphNode* graphNode);
	virtual void visit(NodeEdge* graph);
};

