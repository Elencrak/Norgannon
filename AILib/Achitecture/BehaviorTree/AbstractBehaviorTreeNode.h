#pragma once
#include <vector>
#include "BehaviorTreeDescriptor.h"

namespace AILib
{
	class AbstractBehaviorTreeNode
	{
	public:

		/// Execute Behavior node code
		virtual bool ExecuteNode() = 0;

		/// Check all node descriptors
		/// @return True if all conditions are checked, else return false
		virtual bool CheckNode();

		/// Add a child node to this node
		virtual void AddChildNode();

		/// Add a child node at a specific position
		virtual void AddChildNode(int position);

		virtual void AddDescriptor(BehaviorTreeDescriptor descriptor);

	private:

		std::vector<BehaviorTreeDescriptor> _descriptors;

	protected:
		std::vector<AbstractBehaviorTreeNode> _childrenNodes;
	};
}

