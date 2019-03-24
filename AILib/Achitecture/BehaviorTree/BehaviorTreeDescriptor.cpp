#include "stdafx.h"
#include "BehaviorTreeDescriptor.h"


namespace AILib
{
	BehaviorTreeDescriptor::BehaviorTreeDescriptor(std::function<bool()> condition)
	{
		_condition = condition;
	}

	BehaviorTreeDescriptor::~BehaviorTreeDescriptor()
	{

	}

	bool BehaviorTreeDescriptor::Check()
	{
		return _condition();
	}
}
