#ifndef __CLIENT__
#define __CLIENT__

enum ErrorClient
{
    NO_ERROR,
    CREATION_ERROR,
    INVALID_ADDRESS,
    CONNECTION_FAILED
};

class Client
{
public:
    Client(int port);
    ~Client();

    /* Connect to the server
    */
    ErrorClient connect();

    /*  Handle communication
    */
    void start();

    /*  Send a message to the server
    */
    void message();
    
    /*  Recieve a message from the server
    */
    void recieve();
    
    /*  prints the error message related to the passed value
    */
    void printError(ErrorClient err);
private:
    int sockfd; // socket file descri
    int port;
    bool connected; // true if connection is established
    static const int DEFAULT_PORT;
};

#endif//__CLIENT__