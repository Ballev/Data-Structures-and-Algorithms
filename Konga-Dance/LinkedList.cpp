#include "LinkedList.h"


LinkedList::LinkedList() : frontPtr(nullptr), backPtr(nullptr), curSize(0)
{}


LinkedList::~LinkedList() {

	clean();

}

void LinkedList::addAtEnd(const Student & newStudent) {

	if (isEmpty()) {

		frontPtr = new Node(newStudent);
		backPtr = frontPtr;
		++curSize;
		return;

	}

	Node* newNode = new Node(newStudent);
	
	backPtr->nextPtr;
	context.back_ptr = n;
	++curSize;

}

void LinkedList::addAtBeg(const Student & newStudent) {

	if (isEmpty()) {

		frontPtr = new Node(newStudent);
		backPtr = frontPtr;
		++curSize;
		return;
	
	}

	Node* newNode = new Node(newStudent);
	newNode->nextPtr = frontPtr;
	frontPtr = newNode;
	++curSize;

}

void LinkedList::addAtPos(const Student &, size_t)
{
}

const size_t LinkedList::gerCurSize() const {

	return curSize;

}

void LinkedList::clean() {

	Node* d;

	while (frontPtr != nullptr) {
		
		d = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete d;
	
	}

	frontPtr = nullptr;
	backPtr = nullptr;
	curSize = 0;

}

void LinkedList::copyFrom(const LinkedList & other) {

	if (other.isEmpty())
		return;

	curSize = other.curSize;

}

bool LinkedList::isEmpty() {

	return curSize == 0;
	
}

bool LinkedList::isComparable(const Student & newStudent, size_t pos) {

	if (newStudent.getFaculty() == -1) {

		std::cerr << "This student is a spy! He is from other University!" << std::endl;
		return false;

	}

	if ((newStudent.getFaculty() == 0 && newStudent.getFaculty == 2) || (newStudent.getFaculty == 1 && newStudent.getFaculty == 0) {

		std::cerr << "This student is a spy! He is from other University!" << std::endl;
		return false;

	}
}
