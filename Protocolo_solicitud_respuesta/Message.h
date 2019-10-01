
#define TAM_MAX_DATA 4000
class Code
{
    public:
        enum kindMessage: int {solicitud = 0, respuesta};
        enum allowedOperations: int {suma = 1};
};


class Message {

    public:
        Code::kindMessage messageType;    
        unsigned int requestId;
        Code::allowedOperations operationId;
        char arguments[TAM_MAX_DATA];
};

