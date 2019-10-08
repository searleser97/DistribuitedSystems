#ifndef MESSAGE_H
#define MESSAGE_H

#define TAM_MAX_DATA 50

class Message {
	public:
		enum kindMessages: int {request, reply};
		enum allowedOperations: int {sum, transfer, getBalance};

		Message::kindMessages messageType;    
		uint64_t requestId;
		Message::allowedOperations operationId;
		char arguments[TAM_MAX_DATA];
		size_t length;
};

#endif
