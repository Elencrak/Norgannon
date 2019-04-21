#include "Descriptor.h"


namespace BehaviorTree
{
	Descriptor::Descriptor(std::function<bool()> condition)
	{
		_condition = condition;
	}

	Descriptor::~Descriptor()
	{

	}

	bool Descriptor::Check()
	{
		return _condition();
	}
}
