/**
 * Copyright (C) 2019-2020 Tristan
 * For conditions of distribution and use, see copyright notice in the COPYING file.
 */

#ifndef SERVER_H
#define SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef int socket_t;

/**
 * Creates a socket on the defined ports and binds+listens to it.
 */
socket_t *server_create_socket(uint16_t port);

#ifdef __cplusplus
}
#endif

#endif /* SERVER_H */
 
