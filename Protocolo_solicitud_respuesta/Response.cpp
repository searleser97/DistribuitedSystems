#include "Response.h"
#include <string.h>

Respuesta::Respuesta(int port)
{
   socketlocal = new SocketDatagrama(port);

}
Message *Respuesta::getRequest()
{
    PaqueteDatagrama pq(sizeof(Message));
    Message *response;

    socketlocal->recibe(pq);
    strcpy(IP, pq.obtieneDireccion());
    port = pq.obtienePuerto();

    Message* msg = (Message*) pq.obtieneDatos();
    operation = msg->operationId;
    requestId = msg->requestId;

    return msg;
}

void Respuesta::sendReply(const char *respuesta)
{
    Message *msg = new Message();
    memcpy(msg->arguments, respuesta, sizeof(msg->arguments));
    msg->messageType = Code::respuesta;
    msg->operationId = operation;
    msg->requestId = requestId;
    PaqueteDatagrama paquete((char*) msg, sizeof(msg), IP, port );
    
    socketlocal->envia(paquete);

}