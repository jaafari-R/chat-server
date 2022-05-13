#ifndef __CLIENT__
#define __CLIENT__

class Client
{
public:
    Client(int port);
    ~Client();

    /* Connect to the server
    */
    void connect();

    /*  Handle communication
    */
    void start();

    /*  Send a message to the server
    */
    void message();
    /*  Recieve a message from the server
    */
    void recieve();
private:
    int sockfd; // socket file descri
    int port;
    bool connected; // true if connection is established
};

#endif//__CLIENT__