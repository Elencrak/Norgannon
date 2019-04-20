#pragma once
#include "AbstractBehaviorTreeNode.h"

namespace AILib
{
	class BehaviorTreeSequence : public AbstractBehaviorTreeNode
	{

	public:

		BehaviorTreeSequence();
		~BehaviorTreeSequence();

		// Inherited via AbstractBehaviorTreeNode
		virtual bool ExecuteNode() override;
	};
}