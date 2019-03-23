// Leuchars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "Helpers.h"
#include "enet/enet.h"
#include <vector>
#include <assert.h>

//struct Message
//{
//	int Id;
//	std::string Data;
//	Message() {
//		std::cout << "Default" << std::endl;
//	};
//	Message(const Message& m)
//	{
//		Id = m.Id;
//		Data = m.Data;
//		std::cout << "By copy" << std::endl;		
//	}
//	Message(int id, std::string data)
//	{
//		Id = id;
//		Data = data;
//		std::cout << "Two params" << std::endl;
//	}
//};


//template<class TData>
//void ReadMessage(void* data, Message<TData>& message)
//{
//	int messageType = 10;
//	memcpy(&messageType, data, sizeof(int))
//}


int main()
{
	if (enet_initialize() != 0)
	{
		std::cout << "Enet lib cannot initialized correctly." << std::endl;
	}
	else
	{
		std::cout << "Enet initialized ..." << std::endl;
	}

	ENetAddress address;
	ENetHost * server;
	/* Bind the server to the default localhost.     */
	/* A specific host address can be specified by   */
	/* enet_address_set_host (& address, "x.x.x.x"); */
	address.host = ENET_HOST_ANY;
	/* Bind the server to port 1234. */
	address.port = 1234;
	server = enet_host_create(&address /* the address to bind the server host to */,
		32      /* allow up to 32 clients and/or outgoing connections */,
		2      /* allow up to 2 channels to be used, 0 and 1 */,
		0      /* assume any amount of incoming bandwidth */,
		0      /* assume any amount of outgoing bandwidth */);
	if (server == NULL)
	{
		std::cout << ("An error occurred while trying to create an ENet server host.") << std::endl;
		exit(EXIT_FAILURE);
	}

	ENetEvent event;
	while (enet_host_service(server, &event, 1000000) > 0)
	{
		int test = 1;
		switch (event.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
			printf("A new client connected from %x:%u.\n",
				event.peer->address.host,
				event.peer->address.port);
			/* Store any relevant client information here. */			
			event.peer->data = (void*) "Client information";
			break;
		case ENET_EVENT_TYPE_RECEIVE:		
		{	
			printf("A packet of length %u containing %s was received from %s on channel %u.\n",
				event.packet->dataLength,
				event.packet->data,
				event.peer->data,
				event.channelID);
			/* Clean up the packet now that we're done using it. */
			TowerControl::DefineType(event.packet->data);
			//std::cout << event.packet->data << std::endl;
			//		
			//Message* current = reinterpret_cast<Message*>(event.packet->data);								
			//Message test;
			//assert(event.packet->dataLength == sizeof(Message));
			//memcpy(&test, event.packet->data, event.packet->dataLength);

			enet_packet_destroy(event.packet);	
			break;
		}
		case ENET_EVENT_TYPE_DISCONNECT:
			printf("%s disconnected.\n", event.peer->data);
			/* Reset the peer's client information. */
			event.peer->data = NULL;
			break;
		}
	}

	
	enet_host_destroy(server);

	return 0;
}