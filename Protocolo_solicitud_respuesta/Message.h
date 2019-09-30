
#define TAM_MAX_DATA 4000
class Code
{
    enum kindMessage: int {solicitud = 0, respuesta};
    enum allowedOperations: int {suma = 1};
};


class Message {

    public:
        int messageType;    
        unsigned int requestId;
        int operationId;
        char arguments[TAM_MAX_DATA];
};

