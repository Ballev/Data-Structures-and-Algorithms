// Class DynamicArray is used as a container to store all the Konga queues.
// The access to the queues will be faster with dynamic array.


#ifndef __DYNAMICARRAY_HEADER__
#define __DYNAMICARRAY_HEADER__

#include "LinkedList.h"

typedef LinkedList queue;

class DynamicArray {

public:

	DynamicArray();
	DynamicArray(const queue&);
	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);
	~DynamicArray();

public:

	void add(const queue&);
	void removeLast();
	void insertAt(const queue&, size_t);
	void removeAt(size_t);
	const size_t getCurSize() const;
	void appendQueues(LinkedList&, const LinkedList&);
	void print();

private:
	
	void clean();
	void resize();
	void copyFrom(const DynamicArray &);

private:

	queue* arr;
	size_t curSize;
	size_t cap;

};

#endif // !__DYNAMICARRAY_HEADER__