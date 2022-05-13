#ifndef __SERVER__
#define __SERVER__

const int Server::DEFAULT_PORT = 17280;

/*
    
*/
class Server
{
public:
    // TODO
    Server(int port = DEFAULT_PORT);
    // TODO
    ~Server();

    //TODO
    /*  Opens/starts the server
        The server listens on this->port
    */
    void start();

private:
    //TODO
    /*  Called when an error occurs
    */
    void error();

    //TODO
    /*  Sends a response to the client
    */
    void respond();

    //TODO
    /*  Reads a request from a client
    */
    void recieve();
    
    int port; // the port the server listens on.
    const static int DEFAULT_PORT;
};

#endif//__SERVER__