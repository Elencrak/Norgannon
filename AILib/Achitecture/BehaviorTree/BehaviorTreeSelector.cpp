#include "stdafx.h"
#include "BehaviorTreeSelector.h"
#include "BehaviorTreeDescriptor.h"

namespace AILib
{

	BehaviorTreeSelector::BehaviorTreeSelector()
	{
	}


	BehaviorTreeSelector::~BehaviorTreeSelector()
	{
	}

	bool BehaviorTreeSelector::ExecuteNode()
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
