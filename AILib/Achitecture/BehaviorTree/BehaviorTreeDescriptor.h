#pragma once
#include <functional>

namespace AILib
{

	class BehaviorTreeDescriptor
	{
	public:
		BehaviorTreeDescriptor(std::function<bool()> condition);
		~BehaviorTreeDescriptor();

		bool Check();

	private:

		std::function<bool()> _condition;
	};

}
