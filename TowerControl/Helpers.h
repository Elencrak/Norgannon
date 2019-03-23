#pragma once

namespace TowerControl
{
	enum class IDs
	{
		UPDATE_POSITION = 1
	};

	template<class TData>
	struct Message
	{
		int id;
		TData data;
	};
	
	void DefineType(void* data);

	template<class TData>
	void writeMessage(void*& data, int& size, Message<TData> message)
	{
		int messageSize = sizeof(int) + sizeof(message);
		data = new char[messageSize];
		char* messageContent = static_cast<char*>(data);
		memcpy(messageContent, &messageSize, sizeof(int));
		memcpy(messageContent + sizeof(int), &message, sizeof(message));
		size = messageSize;
	}
}