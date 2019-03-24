#pragma once
#include "BehaviorTreeSelector.h"
#include <memory>

namespace AILib
{

	class BehaviorTree
	{
	public:
		BehaviorTree();
		~BehaviorTree();

	private:
		std::shared_ptr<BehaviorTreeSelector> root;
	};
}

