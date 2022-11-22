#ifndef SIMPLESOCKET_HPP
#define SIMPLESOCKET_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace schung {
    class SimpleSocket {
    private:
        struct sockaddr_in address;
        int sock;
        int connection;
    public:
        SimpleSocket(int domain, int service, int protocol, int port,
                     u_long interface);
        virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
        void test_connection(int);

        const sockaddr_in &getAddress() const;
        int getSock() const;
        int getConnection() const;

        void setConnection(int connection);
    };
}
#endif //SIMPLESOCKET_HPP
