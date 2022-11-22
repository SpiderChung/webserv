//
// Created by Spider Chung on 11/21/22.
//

//#include "SimpleSocket.hpp"
#include <iostream>
#include <stdio.h>

#include "webserv.hpp"

int main()
{
    std::cout << "Starting..." << std::endl;
    std::cout << "Binding socket..." << std::endl;
    schung::BindingSocket bs = schung::BindingSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);
    std::cout << "Listening socket..." << std::endl;
    schung::ListeningSocket ls = schung::ListeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
    std::cout << "Success..." << std::endl;

}
