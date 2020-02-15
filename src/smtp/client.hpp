/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#ifndef SMTP_CLIENT_HPP
#define SMTP_CLIENT_HPP

#include "smtp.hpp"

namespace SMTP {
	class Client {
	private:
		SMTPServer *Server;
		int Socket;
	public:
		Client(SMTPServer *server, int socket);
		void Handle();
	};
}

#endif /* SMTP_CLIENT_HPP */
