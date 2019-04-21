#pragma once
#include <vector>
#include <memory>
#include "Descriptor.h"

namespace BehaviorTree
{
	class AbstractNode
	{
	public:

		/// Execute Behavior node code
		virtual bool ExecuteNode() = 0;

		/// Check all node descriptors
		/// @return True if all conditions are checked, else return false
		virtual bool CheckNode();

		/// Add a child node to this node
		virtual void AddChildNode(std::shared_ptr<AbstractNode> node);

		/// Add a child node at a specific position
		virtual void AddChildNode(std::shared_ptr<AbstractNode> node, int position);

		virtual void AddDescriptor(Descriptor descriptor);

	private:

		std::vector<Descriptor> _descriptors;

	protected:
		std::vector<std::shared_ptr<AbstractNode>> _childrenNodes;
	};
}

