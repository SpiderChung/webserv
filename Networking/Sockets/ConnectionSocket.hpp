//
// Created by Spider Chung on 11/22/22.
//

#ifndef CONNECTIONSOCKET_HPP
#define CONNECTIONSOCKET_HPP

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace schung {

    class ConnectionSocket : public SimpleSocket{
    public:
        ConnectionSocket(int domain, int service, int protocol,
                         int port, u_long interface);

        int connect_to_network(int sock, struct sockaddr_in address);

    };
}

#endif //CONNECTIONSOCKET_HPP
