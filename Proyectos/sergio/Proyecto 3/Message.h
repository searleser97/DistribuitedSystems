#ifndef MESSAGE_H
#define MESSAGE_H

#define TAM_MAX_DATA 30000

class Message {
	public:
		enum Type: int {request, reply};
		enum AllowedOperations: int {sum, transfer, getBalance, image};

		Message::Type type;    
		uint64_t requestId;
		Message::AllowedOperations operation;
		char arguments[TAM_MAX_DATA];
		size_t length;
};

#endif
