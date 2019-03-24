#include "stdafx.h"
#include "BehaviorTreeTask.h"

namespace AILib
{

	BehaviorTreeTask::BehaviorTreeTask(std::function<bool()> action)
	{
		_action = action;
	}


	BehaviorTreeTask::~BehaviorTreeTask()
	{
	}

	bool AILib::BehaviorTreeTask::ExecuteNode()
	{
		return _action();
	}
}
