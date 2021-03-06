// Winkie.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <enet\enet.h>
#include <thread>
#include <bitset>
//Includes
#include "Helpers.h"

void NetworkLoop(ENetHost* networkCLient, int timeout)
{
	bool shutdown = false;
	ENetEvent event;
	while(!shutdown)
	{
		while (enet_host_service(networkCLient, &event, timeout) > 0)
		{		
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
				printf("A packet of length %u containing %s was received from %s on channel %u.\n",
					event.packet->dataLength,
					event.packet->data,
					event.peer->data,
					event.channelID);
				/* Clean up the packet now that we're done using it. */
				enet_packet_destroy(event.packet);

				break;

			case ENET_EVENT_TYPE_DISCONNECT:
				printf("%s disconnected.\n", event.peer->data);
				/* Reset the peer's client information. */
				event.peer->data = NULL;
				shutdown = true;
			}		
		}
	}
}

// Winkie is the client of the Leuchars base airforce.
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

	ENetHost * client;
	
	client = enet_host_create(NULL /* create a client host */,
		1 /* only allow 1 outgoing connection */,
		2 /* allow up 2 channels to be used, 0 and 1 */,
		0 /* assume any amount of incoming bandwidth */,
		0 /* assume any amount of outgoing bandwidth */);
	if (client == NULL)
	{
		std::cout << "An error occurred while trying to create an ENet client host." << std::endl;
		exit(EXIT_FAILURE);
	}

	ENetAddress address;
	ENetPeer *peer;
	/* Connect to some.server.net:1234. */
	enet_address_set_host(&address, "127.0.0.1");
	address.port = 1234;
	/* Initiate the connection, allocating the two channels 0 and 1. */
	peer = enet_host_connect(client, &address, 2, 0);
	if (peer == NULL)
	{
		fprintf(stderr,
			"No available peers for initiating an ENet connection.\n");
		exit(EXIT_FAILURE);
	}
	std::thread t1(NetworkLoop, client, 3);

	int messageNumber(0);
	
	while (true)
	{
		std::string command;
		std::cout << "Type commande" << std::endl;
		std::getline(std::cin, command);
		TowerControl::Message<float> myMsg;
		myMsg.id = 8000;
		myMsg.data = 5.5f;
		void* data;
		int size;
		TowerControl::writeMessage<float>(data, size, myMsg);

		char* byteData = (char*)data;
		int testByte = 10;
		printf("%8lx\n", testByte);
		for (int i = 0; i < 5; ++i)
		{
			std::cout << byteData[i] << std::endl;
			printf("%8lx\n", byteData[i]);
			printf(" Value of x %x by printf", byteData[i]);
		}

		ENetPacket * packet = enet_packet_create(data,
			size,
			ENET_PACKET_FLAG_RELIABLE);
		if (command == "exit")
		{
			break;
		}
		else
		{
			enet_peer_send(peer, 0, packet);		
			enet_host_flush(client);
			messageNumber++;
		}		
	}

	enet_peer_disconnect(peer, 0);

	t1.join();
	/*std::thread t2(NetworkLoop, client, 3000);
	t2.join();*/
	enet_host_destroy(client);

    return 0;
}