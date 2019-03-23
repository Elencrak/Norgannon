#pragma once
#include <vector>
#include <thread>
#include "Connexion.h"
#include "Configuration.h"

// TODO fixme : Find a way to froward delcare a struct
#include <enet\enet.h>
//Forward declare 
//struct ENetHost;

namespace TowerControl
{
	

	class Client
	{
	public:
		Client();
		Client(Configuration config);
		~Client();

		void Connect();		
		void Disconnect();
		void Send();

		// Enet lib
		ENetPeer* peer;
		ENetHost* client;


	private:
		void Initialize();
		void networkLoop(ENetHost* networkCLient, int timeout);
		
		Configuration config;
		std::thread networkThread;

		// Enet lib
/*		ENetPeer* peer;
		ENetHost* client;*/
		
	};
}