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
	std::shared_ptr<BehaviorTreeSelector> BehaviorTree::GetRoot()
	{
		return root;
	}

	void BehaviorTree::Run()
	{
		root->ExecuteNode();
	}
}
