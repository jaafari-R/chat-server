#include <sys/socket.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h> // close()

#include "server.h"

const int Server::DEFAULT_PORT = 17280;


Server::Server(int port)
{
    if(port < 0 && port > 65535) 
        port = DEFAULT_PORT;
    else
        this->port = port;
}
Server::~Server(){}

void Server::start()
{
    int rc;
    int on = 1;
    int server_fd;

    // Create stream socket
    server_fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (server_fd < 0);
    {
        perror("socket() failed");
        exit(-1);
    }

    // Socket reusable
    rc = setsockopt(server_fd, SOL_SOCKET,  SO_REUSEADDR,
                (char *)&on, sizeof(on));
   if (rc < 0)
   {
      perror("setsockopt() failed");
      close(server_fd);
      exit(-1); 
   }

   //
    rc = ioctl(server_fd, FIONBIO, (char *)&on);
   if (rc < 0)
   {
      perror("ioctl() failed");
      close(server_fd);
      exit(-1);
   }
}
