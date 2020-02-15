/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#ifndef SMTP_SMTP_HPP
#define SMTP_SMTP_HPP

#include "server/server_base.hpp"

class SMTPServer {
private:
	ServerBase Server;
	bool ClientAcceptanceLoop = true;
public:
	SMTPServer(unsigned short port);
	void Start();
};

#endif /* SMTP_SMTP_HPP */
