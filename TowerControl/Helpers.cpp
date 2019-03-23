#include "stdafx.h"
#include "Helpers.h"
#include <iostream>

namespace TowerControl
{

	void DefineType(void* data)
	{
		int size;
		memcpy(&size, data, sizeof(int));
		//Create message and remove header.
		//char* messageContent = static_cast<char*>(data);

		char* message = new char[size];
		memcpy(message, data, size);

		int header;
		memcpy(&header, message, sizeof(int));

		Message<float> typeMessage;
		memcpy(&typeMessage, message + sizeof(header), sizeof(Message<float>));
	}
}