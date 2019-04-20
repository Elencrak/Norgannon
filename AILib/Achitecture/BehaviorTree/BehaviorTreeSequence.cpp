#include "BehaviorTreeSequence.h"

namespace AILib
{

	BehaviorTreeSequence::BehaviorTreeSequence()
	{

	}

	BehaviorTreeSequence::~BehaviorTreeSequence()
	{

	}

	bool BehaviorTreeSequence::ExecuteNode()
	{
		for (auto child : _childrenNodes)
		{
			if (!child->CheckNode() || !child->ExecuteNode())
			{
				return false;
			}
		}
		return true;
	}
}
