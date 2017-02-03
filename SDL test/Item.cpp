#include "Item.h"

void Item::removeFromNode()
{
	if (node)
	{ 
		node->removeItem(shared_from_this());
	}
}
