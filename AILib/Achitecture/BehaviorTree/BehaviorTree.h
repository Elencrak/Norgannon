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

		std::shared_ptr<BehaviorTreeSelector> GetRoot();
		void Run();

	private:
		std::shared_ptr<BehaviorTreeSelector> root;
	};
}

