/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#include "smtp.hpp"
#include "client.hpp"

#include <iostream>
#include <thread>

SMTPServer::SMTPServer(uint16_t port) : Server(port) {
}

void SMTPServer::Start() {
	if (!Server.Start()) {
		std::cerr << "Failed to start server on port: " << Server.Port << std::endl;
		return;
	}

	std::cout << "Started SMTP Server on port: " << Server.Port << std::endl;
	
	while (ClientAcceptanceLoop) {
		int socket = Server.Accept();
		if (socket < 0) {
			ClientAcceptanceLoop = false;
			Server.Stop();
			std::cerr << "ServerBase::Accept failure!" << std::endl;
		}

		SMTP::Client *client = new SMTP::Client(this, socket);
		std::thread(&SMTP::Client::Handle, client).detach();
	}
}
