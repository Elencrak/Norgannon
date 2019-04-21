#pragma once
#include "AbstractNode.h"


namespace BehaviorTree
{
	class Descriptor;

	class Selector : public AbstractNode
	{
	public:
		Selector();
		~Selector();

		// Inherited via IBehaviorTreeNode
		virtual bool ExecuteNode() override;
		
	};
}

