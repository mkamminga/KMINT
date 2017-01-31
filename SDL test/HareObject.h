#pragma once
#include "BaseObject.h"
class HareObject :
	public BaseObject
{
public:
	HareObject(int x, int y) : BaseObject(x, y) {}

	virtual void accept(BaseVisitor* base);
};

