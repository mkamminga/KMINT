#include "HareObject.h"

void HareObject::accept(BaseVisitor * base)
{
	base->visit(this);
}
