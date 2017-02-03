#pragma once
#include "BaseObject.h"

class PillItem;

class CowObject : public BaseObject
{
public:
	CowObject(int x, int y) : BaseObject(x, y) {}

	virtual void accept(BaseVisitor* base);
	void use(PillItem* );
};

