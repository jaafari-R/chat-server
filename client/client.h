#ifndef __CLIENT__
#define __CLIENT__

class Client
{
public:
    Client();
    ~Client();

    /* Connect to the server
    */
    void connect();

    /*  Send a message to the server
    */
    void message();
    /*  Recieve a message from the server
    */
    void recieve();
private:
    int port;
};

#endif//__CLIENT__