#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "client.h"

const int Client::DEFAULT_PORT = 17280;

Client::Client(int port)
{
    connected = false;
    if(port < 0 && port > 65535) 
        port = DEFAULT_PORT;
    else
        this->port = port;
}

Client::~Client() {}

ErrorClient Client::initConnection()
{
    struct sockaddr_in server_addr;
    
    if(sockfd = socket(AF_INET, SOCK_STREAM, 0) <= 0)
    {
        // socket creation error
        return CREATION_ERROR;
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    if(inet_pton(AF_INET, "127.0.0.1", server_addr.sin_addr))
    {
        // invalid address
        return INVALID_ADDRESS;
    }
    
    if(connect(sockfd, (sockaddr *) &server_addr, sizeof(server_addr)))
    {
        // connection failed
        return CONNECTION_FAILED;
    }
    
    return NO_ERROR;
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