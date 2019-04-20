#pragma once
#include "AbstractBehaviorTreeNode.h"

class BehaviorTreeDescriptor;

namespace AILib
{

	class BehaviorTreeSelector : public AbstractBehaviorTreeNode
	{
	public:
		BehaviorTreeSelector();
		~BehaviorTreeSelector();

		// Inherited via IBehaviorTreeNode
		virtual bool ExecuteNode() override;
		
	};
}

