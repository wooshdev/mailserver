/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#ifndef IO_SOCKET_HPP
#define IO_SOCKET_HPP

#include <string>

namespace IO {
	class Stream {
	private:
		int Socket;
	public:
		Stream(int socket);
		std::string *ReadLine();
		bool Read(char *buffer, const unsigned int length);
		bool Write(const char *buffer, const unsigned int length);
		bool Write(std::string string);
	};
};

#endif /* IO_SOCKET_HPP */
