#include "stdafx.h"
#include "BehaviorTree.h"

namespace AILib
{

	BehaviorTree::BehaviorTree()
	{
		root = std::make_shared<BehaviorTreeSelector>();

	}


	BehaviorTree::~BehaviorTree()
	{
	}
}
