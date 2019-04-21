#pragma once
#include <functional>
#include "AbstractNode.h"

namespace BehaviorTree
{

	class Task : public AbstractNode
	{
	public:
		Task(std::function<bool()> action);
		~Task();

		// Inherited via AbstractBehaviorTreeNode
		virtual bool ExecuteNode() override;

	private:
		std::function<bool()> _action;
	};
}

