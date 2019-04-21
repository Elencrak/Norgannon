#include "Tree.h"

namespace BehaviorTree
{

	Tree::Tree()
	{
		root = std::make_shared<Selector>();

	}


	Tree::~Tree()
	{
	}
	std::shared_ptr<Selector> Tree::GetRoot()
	{
		return root;
	}

	void Tree::Run()
	{
		root->ExecuteNode();
	}
}
