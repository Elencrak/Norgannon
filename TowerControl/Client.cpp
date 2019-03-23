#include "stdafx.h"
#include "Client.h"
#include "Helpers.h"
//Libs include

namespace TowerControl
{
	Client::Client()
	{

	}

	Client::Client(Configuration config)
		: config(config)
	{
		if (enet_initialize() != 0)
		{
			std::cout << "Enet lib cannot initialized correctly." << std::endl;
		}
		else
		{
			std::cout << "Enet initialized ..." << std::endl;
		}
		Initialize();
	}

	Client::~Client()
	{
	}

	void Client::Connect()
	{
		ENetAddress address;
		///* Connect to some.server.net:1234. */
		enet_address_set_host(&address, "127.0.0.1");
		address.port = 1234;
		///* Initiate the connection, allocating the two channels 0 and 1. */
		peer = enet_host_connect(client, &address, 2, 0);
		if (peer == NULL)
		{
			fprintf(stderr,
				"No available peers for initiating an ENet connection.\n");
			exit(EXIT_FAILURE);
		}

		// TODO fixme: i think i need to move this in task.
		// I'm not very sure about thread creation
		networkThread = std::thread(&Client::networkLoop, this, client, 0);
	}


	void Client::networkLoop(ENetHost* networkCLient, int timeout)
	{
		bool shutdown = false;
		ENetEvent event;
		while (!shutdown)
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
	void Client::Disconnect()
	{

	}

	void Client::Send()
	{
		Message<float> myMsg;
		myMsg.id = 8000;
		myMsg.data = 5.5f;
		void* data;
		int size;
		writeMessage<float>(data, size, myMsg);

		ENetPacket * packet = enet_packet_create(data,
			size,
			ENET_PACKET_FLAG_RELIABLE);

		enet_peer_send(peer, 0, packet);
		enet_host_flush(client);
	}

	void Client::Initialize()
	{
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
		else
		{
			std::cout << "Client created" << std::endl;
		}
	}
}