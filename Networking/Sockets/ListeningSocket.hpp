//
// Created by Spider Chung on 11/22/22.
//

#ifndef LISTENINGSOCKET_HPP
#define LISTENINGSOCKET_HPP

#include <stdio.h>

#include "BindingSocket.hpp"
namespace schung {
class ListeningSocket : public BindingSocket {
private:
    int backlog;
    int listening;
public:
    ListeningSocket(int domain, int service, int protocol,
                    int port, u_long interface, int backlog);
    void start_listening();
};
}

#endif //WEBSERV_S_LISTENINGSOCKET_HPP
