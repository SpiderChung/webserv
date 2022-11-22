//
// Created by Spider Chung on 11/22/22.
//

#include "ConnectionSocket.hpp"

schung::ConnectionSocket::ConnectionSocket(int domain, int service,
                                           int protocol, int port,
                                           u_long interface) :
                                           SimpleSocket(domain, service,
                                            protocol, port, interface) {
    setConnection(connect_to_network(getSock(), getAddress()));
    test_connection(getConnection());
}

int schung::ConnectionSocket::connect_to_network(int sock, struct sockaddr_in address) {
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}