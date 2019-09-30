#include "Request.h"
#include "Message.h"

char Request::*doOperation(char *IP, int port, Code::allowedOperations operation, char *arguments)
{   
    SocketDatagrama socket(0);

    PaqueteDatagrama paqueteData;

    if(operation == Code::allowedOperations::suma)
    {       
        paqueteData = PaqueteDatagrama((char*) arguments, 2 * sizeof(int), IP, port);
    }
    else
    {
        throw "Operation not supported";
    }
    
}

Request::Request() { }