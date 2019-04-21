#include "Task.h"

namespace BehaviorTree
{

	Task::Task(std::function<bool()> action)
	{
		_action = action;
	}


	Task::~Task()
	{
	}

	bool Task::ExecuteNode()
	{
		return _action();
	}
}
