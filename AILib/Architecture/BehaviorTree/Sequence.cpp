#include "Sequence.h"

namespace BehaviorTree
{

	Sequence::Sequence()
	{

	}

	Sequence::~Sequence()
	{

	}

	bool Sequence::ExecuteNode()
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
