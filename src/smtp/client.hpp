/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#ifndef SMTP_CLIENT_HPP
#define SMTP_CLIENT_HPP

namespace SMTP {
	class Client;
}
#include "smtp.hpp"

#include "io/stream.hpp"

#include <string>
#include <vector>

namespace SMTP {
	class Client {
	private:
		SMTPServer *Server;
		int Socket;
		IO::Stream Stream;
	public:
		Client(SMTPServer *server, int socket);
		void Handle();
		
		void SendResponse(unsigned code, std::string message);
		void SendResponse(unsigned code, std::vector<std::string> messages);
	};
}

#endif /* SMTP_CLIENT_HPP */
