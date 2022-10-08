#include "server.h"
#include "stdio.h"

int main()
{
    printf("test-1");
    Server server;
    printf("test");
    server.start();
    printf("test2");

    return 0;
}