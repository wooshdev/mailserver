/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#ifndef SERVER_BASE_HPP
#define SERVER_BASE_HPP

#include "server.h"

/* A helper class to work with POSIX TCP sockets in a C++ environment. */
class ServerBase {
protected:
	socket_t Socket;
public:
	unsigned short Port;

	ServerBase(unsigned short port);
	~ServerBase();

	bool Start();
	int Accept();
	void Stop();
};

#endif /* SERVER_BASE_HPP */
