#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "client.h"

Client::Client(int port)
{
    connected = false;
    if(port < 0 && port > 65535) 
        port = DEFAULT_PORT;
    else
        this->port = port;
}

Client::~Client() {}

void Client::connect()
{
    struct sockaddr_in server_addr;
    
    if(sockfd = socket(AF_INET, SOCK_STREAM, 0) <= 0)
    {
        // socket creation error
        return;
    }
    
    server_addr.sin_faminy = AF_INET;
    server_addr.sin_port = htons(port);
    
    if(inet_pton(AF_INET, "127.0.0.1", server_addr.sin_addr))
    {
        // invalid address
        return;
    }
    
    if(connect(sockfd, (sockaddr *) &server_addr, sizeof(server_addr)))
    {
        // connection failed
        return;
    }
}

void Client::printError(ErrorClient err)
{
    switch(err)
    {
        case NO_ERROR:
            break;
        case CREATION_ERROR:
            break;
        case INVALID_ADDRESS:
            break;
        case CONNECTION_FAILED:
            break;
    }
}