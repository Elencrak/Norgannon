#include "AbstractNode.h"

bool BehaviorTree::AbstractNode::CheckNode()
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

void BehaviorTree::AbstractNode::AddChildNode(std::shared_ptr<AbstractNode> node)
{
	_childrenNodes.push_back(node);
}

void BehaviorTree::AbstractNode::AddChildNode(std::shared_ptr<AbstractNode> node, int position)
{
	auto it = _childrenNodes.begin() + position;
	_childrenNodes.insert(it, node);
}

void BehaviorTree::AbstractNode::AddDescriptor(Descriptor descriptor)
{
	_descriptors.push_back(descriptor);
}
