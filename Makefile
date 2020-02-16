# Copyright (C) 2019-2020 Tristan, All Rights Reserved
# For conditions of distribution and use, see copyright notice in the COPYING file.

OUTPUTFILE = bin/server

CFLAGS = -O3 -Wall -g -Isrc
LDFLAGS = -lpthread
CC = c89
CXX = g++

SMTPBINARIES = bin/smtp/server.so bin/smtp/client.so
SUBBINARIES = bin/io/stream.so bin/server.so bin/server_base.so bin/settings.so $(SMTPBINARIES)

$(OUTPUTFILE): src/main.cpp bin/build.txt $(SUBBINARIES)
	$(CXX) $(CFLAGS) -o $@ $< $(SUBBINARIES) $(LDFLAGS)
bin/build.txt: # a hack to create the bin folder only once
	mkdir -p bin/io
	mkdir -p bin/smtp
	touch bin/build.txt
bin/io/stream.so: src/io/stream.cpp src/io/stream.hpp
	$(CXX) -o $@ -c $(CFLAGS) $<
bin/server.so: src/server/server.c src/server/server.h
	$(CC) -o $@ -c $(CFLAGS) $<
bin/server_base.so: src/server/server_base.cpp src/server/server_base.hpp bin/server.so
	$(CXX) -o $@ -c $(CFLAGS) $< bin/server.so
bin/smtp/server.so: src/smtp/smtp.cpp src/smtp/smtp.hpp src/smtp/client.hpp
	$(CXX) -o $@ -c $(CFLAGS) $<
bin/smtp/client.so: src/smtp/client.cpp src/smtp/client.hpp src/smtp/smtp.hpp
	$(CXX) -o $@ -c $(CFLAGS) $<
bin/settings.so: src/settings.cpp src/settings.hpp
	$(CXX) -o $@ -c $(CFLAGS) $<
