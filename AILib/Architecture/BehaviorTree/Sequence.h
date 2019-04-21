#pragma once
#include "AbstractNode.h"

namespace BehaviorTree
{
	class Sequence : public AbstractNode
	{

	public:

		Sequence();
		~Sequence();

		// Inherited via AbstractBehaviorTreeNode
		virtual bool ExecuteNode() override;
	};
}