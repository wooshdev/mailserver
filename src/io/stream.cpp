/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#include "stream.hpp"

#include <unistd.h>

#include <iostream>
#include <vector>

namespace IO {
	Stream::Stream(int socket) : Socket(socket) {}
	
	std::string *Stream::ReadLine() {
		std::vector<char> buffer(128);

		size_t position = 0;
		do {
			if (!Read(buffer.data() + position, 1)) {
				std::cout << "SMTP::Client::Read() Failure!" << std::endl;
				return nullptr;
			}

			if (position > 1 && buffer[position - 1] == '\r' && buffer[position] == '\n') {
				return new std::string(buffer.data(), 0, position - 1);
			}

			position += 1;
		} while (true);

		return nullptr;
	}

	bool Stream::Read(char *buffer, const unsigned int length) {
		unsigned int totalBytesRead = 0;

		do {
			int bytesRead = read(Socket, buffer + totalBytesRead, length - totalBytesRead);

			if (bytesRead < 1) {
				// perror("SMTP::Client:Read");
				return false;
			}

			totalBytesRead += bytesRead;
		} while (totalBytesRead != length);

		return true;
	}

	bool Stream::Write(const char *buffer, const unsigned int length) {
		if (write(Socket, buffer, length) < 0) {
			// perror("SMTP::Client:Write");
			return false;
		}

		return true;
	}

	bool Stream::Write(std::string string) {
		return Write(string.c_str(), string.length());
	}
}
