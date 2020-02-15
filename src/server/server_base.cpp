/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#include "server_base.hpp"

#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

ServerBase::ServerBase(unsigned short port) : Port(port) {
}

ServerBase::~ServerBase() {
	// Stop the socket if it hasn't stopped already.
	if (Socket)
		Stop();
}

bool ServerBase::Start() {
	socket_t *socket = server_create_socket((uint32_t) Port);

	if (!socket)
		return false;

	Socket = *socket;
	free(socket);

	return socket;
}

int ServerBase::Accept() {
	struct sockaddr_in addr;
	unsigned len = sizeof(struct sockaddr_in);

	int client = accept(Socket, (struct sockaddr*)&addr, &len);
	if (client < 0) {
		perror("ServerBase::Accept");
		std::cerr << "ServerBase: Failed to accept client!" << std::endl;
	}

	return client;
}

void ServerBase::Stop() {
	close(Socket);
	Socket = 0;
}
