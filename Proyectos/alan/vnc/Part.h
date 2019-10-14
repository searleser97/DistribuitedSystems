#ifndef Part_H_
#define Part_H_

#define part_size 32768

class Part {
	public:
		size_t offset;
		int id;
		size_t size;
		char name[100];
		char data[part_size];
};

#endif
