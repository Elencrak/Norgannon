#pragma once
#include "Selector.h"
#include <memory>

namespace BehaviorTree
{

	class Tree
	{
	public:
		Tree();
		~Tree();

		std::shared_ptr<Selector> GetRoot();
		void Run();

	private:
		std::shared_ptr<Selector> root;
	};
}

