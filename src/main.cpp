/**
 * Copyright (C) 2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */
#include <cstdlib>
#include <iostream>
#include <thread>

#include "smtp/smtp.hpp"
#include "settings.hpp"

int main(void) {
	std::cout << "Greeting: " << Settings::SMTP::Greeting << std::endl;
	SMTPServer server(25);
	
	std::thread threadImap(&SMTPServer::Start, server);
	
	threadImap.join();
	
	return EXIT_SUCCESS;
}
