#include "CowObject.h"

void CowObject::accept(BaseVisitor* visitor)
{
	visitor->visit(this);
}
