#include "AbstractBehaviorTreeNode.h"

bool AILib::AbstractBehaviorTreeNode::CheckNode()
{
	for (auto descriptor : _descriptors)
	{
		if (!descriptor.Check())
		{
			return false;
		}
	}
	return true;
}

void AILib::AbstractBehaviorTreeNode::AddChildNode(std::shared_ptr<AbstractBehaviorTreeNode> node)
{
	_childrenNodes.push_back(node);
}

void AILib::AbstractBehaviorTreeNode::AddChildNode(std::shared_ptr<AbstractBehaviorTreeNode> node, int position)
{
	auto it = _childrenNodes.begin() + position;
	_childrenNodes.insert(it, node);
}

void AILib::AbstractBehaviorTreeNode::AddDescriptor(BehaviorTreeDescriptor descriptor)
{
	_descriptors.push_back(descriptor);
}
