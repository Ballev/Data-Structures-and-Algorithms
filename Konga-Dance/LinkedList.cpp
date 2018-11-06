#include "LinkedList.h"


LinkedList::LinkedList() : frontPtr(nullptr), backPtr(nullptr), curSize(0)
{}


LinkedList::~LinkedList() {

	clean();

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

bool LinkedList::isEmpty() {

	return curSize == 0;
	
}

bool LinkedList::isComparable(const Student & newStudent, size_t pos) {

	if (newStudent.getFaculty() == -1) {

		std::cerr << "This student is a spy! He is from other University!" << std::endl;
		return false;

	}

	if ((newStudent.getFaculty() == 0  )) {

		std::cerr << "This student is a spy! He is from other University!" << std::endl;
		return false;

	}
}
