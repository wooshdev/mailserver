/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#include "client.hpp"

#include <iostream>

namespace SMTP {
	Client::Client(SMTPServer *server, int socket) : Server(server), Socket(socket) {
	}

	void Client::Handle() {
		
	}
}
