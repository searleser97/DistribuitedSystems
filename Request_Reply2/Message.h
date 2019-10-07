#ifndef MESSAGE_H
#define MESSAGE_H

#define TAM_MAX_DATA 4000

class Message {
	public:
		enum kindMessages: int {request = 0, reply};
		enum allowedOperations: int {sum = 0};

		Message::kindMessages messageType;    
		unsigned int requestId;
		Message::allowedOperations operationId;
		char arguments[TAM_MAX_DATA];
		size_t length;
};

#endif
