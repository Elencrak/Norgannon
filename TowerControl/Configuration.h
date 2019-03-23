#pragma once

class Configuration
{
public:
	Configuration();
	// Need to think how can i put nice options system.
	Configuration(std::string ip, int port, std::string options);
	~Configuration();
};

