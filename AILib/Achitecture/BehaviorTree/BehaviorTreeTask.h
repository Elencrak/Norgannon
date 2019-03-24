#pragma once
#include <functional>
#include "AbstractBehaviorTreeNode.h"

namespace AILib
{

	class BehaviorTreeTask : AbstractBehaviorTreeNode
	{
	public:
		BehaviorTreeTask(std::function<bool()> action);
		~BehaviorTreeTask();

		// Inherited via AbstractBehaviorTreeNode
		virtual bool ExecuteNode() override;

	private:
		std::function<bool()> _action;
	};
}

