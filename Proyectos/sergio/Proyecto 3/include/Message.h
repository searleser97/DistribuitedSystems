#ifndef MESSAGE_H
#define MESSAGE_H

class Message {
	public:
		enum Type: int {request, reply};
		enum AllowedOperations: int {sum, transfer, getBalance, image};
		static const size_t MAX_DATA_SIZE = 35000;
		Message::Type type;    
		uint64_t requestId;
		Message::AllowedOperations operation;
		char arguments[MAX_DATA_SIZE];
		size_t length;
		bool MF;
		unsigned offset;
};
#endif