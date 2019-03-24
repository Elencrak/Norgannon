#include "stdafx.h"
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

void AILib::AbstractBehaviorTreeNode::AddChildNode()
{
}

void AILib::AbstractBehaviorTreeNode::AddChildNode(int position)
{
}

void AILib::AbstractBehaviorTreeNode::AddDescriptor(BehaviorTreeDescriptor descriptor)
{
	_descriptors.push_back(descriptor);
}
