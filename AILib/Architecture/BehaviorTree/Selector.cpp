#include "Selector.h"
#include "Descriptor.h"

namespace BehaviorTree
{

	Selector::Selector()
	{
	}


	Selector::~Selector()
	{
	}

	bool Selector::ExecuteNode()
	{
		for (auto child : _childrenNodes)
		{
			if (child->CheckNode() && child->ExecuteNode())
			{
				return true;
			}
		}
		return false;
	}
}
