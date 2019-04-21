#pragma once
#include <functional>

namespace BehaviorTree
{

	class Descriptor
	{
	public:
		Descriptor(std::function<bool()> condition);
		~Descriptor();

		bool Check();

	private:

		std::function<bool()> _condition;
	};

}
