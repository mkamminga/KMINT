#include "CowObject.h"
#include "PillItem.h"

void CowObject::accept(BaseVisitor* visitor)
{
	visitor->visit(this);
}

void CowObject::use(PillItem *)
{
}
