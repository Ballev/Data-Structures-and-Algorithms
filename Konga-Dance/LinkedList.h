//Lists with all the operations for adding/removing students.
// Linked list is useful, because insertion and deletion are faster.


#ifndef __LINKEDLIST_HEADER__
#define __LINKEDLIST_HEADER__

#include "Student.h"

class LinkedList {

public:
	
	LinkedList();
	LinkedList(const Student&);
	LinkedList(const LinkedList&);
	LinkedList& operator=(const LinkedList&);
	~LinkedList();

	//Functions for working with the queues.
public:

	void addAtEnd(const Student&);
	void addAtBeg(const Student&);
	void addAtPos(const Student&, size_t);
	void removeLast();
	void removeFirst();
	void remove(size_t);
	const size_t gerCurSize() const;

private:

	void clean();
	void copyFrom(const LinkedList&);
	bool isEmpty();
	bool isComparable(const Student&, size_t pos);

private:

	struct Node {

		Node* nextPtr;
		Student data;

		// Constructor for the Node.
		Node(const Student& _data, Node* _nextPtr = nullptr) :
			data(_data), nextPtr(_nextPtr) {}

	};

private: 

	Node* frontPtr;
	Node* backPtr;
	size_t curSize;

};

#endif // !__LINKEDLIST_HEADER__
