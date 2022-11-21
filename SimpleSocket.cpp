//
// Created by Spider Chung on 11/21/22.
//

#include "SimpleSocket.hpp"

schung::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface) {
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    sock = socket(domain, service, protocol);
    test_connection(sock);

    connection = connect_to_network(sock, address);
    test_connection(connection);
}

void schung::SimpleSocket::test_connection(int item_to_test) {
    if (item_to_test < 0) {
        perror("Failed to connect..");
        exit(EXIT_FAILURE);
    }
}

const sockaddr_in &schung::SimpleSocket::getAddress() const {
    return address;
}

int schung::SimpleSocket::getSock() const {
    return sock;
}

int schung::SimpleSocket::getConnection() const {
    return connection;
}
