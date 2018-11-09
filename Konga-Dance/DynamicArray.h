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
	void removeLast(size_t);
	void removeFirst(size_t);
	void insertAt(const queue&, size_t);
	void removeAt(const string&, size_t);
	const size_t getCurSize() const;
	void mergeQueues(size_t, size_t);
	void append(const Student&, size_t);
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