//
// Created by Spider Chung on 11/22/22.
//

#include "ListeningSocket.hpp"

schung::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface,
                                         int backlog) :
        BindingSocket(domain, service, protocol, port, interface) {
    this->backlog = backlog;
    start_listening();
    test_connection(listening);
}

void schung::ListeningSocket::start_listening() {
    this->listening = listen(getConnection(), backlog);
}