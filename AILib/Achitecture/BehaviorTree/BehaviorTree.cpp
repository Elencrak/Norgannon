#include "stdafx.h"
#include "BehaviorTree.h"
#include "BehaviorTreeSelector.h"

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
