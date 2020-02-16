/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#include "client.hpp"

#include <iostream>

#include "settings.hpp"

namespace SMTP {
	Client::Client(SMTPServer *server, int socket) : Server(server), Socket(socket), Stream(IO::Stream(socket)) {
	}

	void Client::Handle() {
		/* Send greeting (RFC 5321 Section 4.2) */
		SendResponse(220, Settings::SMTP::Greeting);
		
		std::cout << "Client::Handle()" << std::endl;
		std::string *str;
		while ((str = Stream.ReadLine()) != nullptr) {
			std::cout << "ReadLine> '" << *str << "'" << std::endl;
		}
		std::cout << "Client::Handle exit()" << std::endl;
	}
	
	void Client::SendResponse(unsigned code, std::string message) {
		Stream.Write(code + " " + message + "\r\n");
	}

	void Client::SendResponse(unsigned code, std::vector<std::string> messages) {
		for (unsigned long i = 0; i < messages.size(); i++) {
			Stream.Write(code + (i == messages.size() - 1 ? " " : "-") + messages[i] + "\r\n");
		}
	}
}
