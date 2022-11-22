//
// Created by Spider Chung on 11/22/22.
//

#include "BindingSocket.hpp"

schung::BindingSocket::BindingSocket(int domain, int service,
                                     int protocol, int port,
                                     u_long interface) : SimpleSocket(domain, service,
                                                                      protocol, port, interface) {
    setConnection(connect_to_network(getSock(), getAddress()));
    test_connection(getConnection());
}

int schung::BindingSocket::connect_to_network(int sock,
                                              struct sockaddr_in address) {
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}