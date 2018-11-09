#include "LinkedList.h"


LinkedList::LinkedList() : frontPtr(nullptr), backPtr(nullptr), curSize(0)
{}

LinkedList & LinkedList::operator=(const LinkedList & other) {

	if (this != &other) {

		clean();
		frontPtr = other.frontPtr;
		backPtr = other.backPtr;
		curSize = other.curSize;

	}

	return *this;

}

LinkedList::~LinkedList() {

	clean();

}

void LinkedList::addAtEnd(const Student & newStudent) {

	if (isEmpty()) {

		frontPtr = new(std::nothrow) Node(newStudent);
		backPtr = frontPtr;
		++curSize;
		return;

	}

	Node* tempNode = new(std::nothrow) Node(newStudent);
	backPtr->nextPtr = tempNode;
	backPtr = backPtr->nextPtr;
	++curSize;

}

void LinkedList::addAtBeg(const Student & newStudent) {

	if (isEmpty()) {

		frontPtr = new(std::nothrow) Node(newStudent);
		backPtr = frontPtr;
		++curSize;
		return;
	
	}

	Node* tempNode = new(std::nothrow) Node(newStudent);
	tempNode->nextPtr = frontPtr;
	frontPtr = tempNode;
	++curSize;

}

void LinkedList::addAtPos(const Student & newStudent, size_t pos) {

	if (isEmpty()) {
	
		addAtBeg(newStudent);
		++curSize;
		return;
	
	}
	
	if (pos > curSize || pos == 0) {

		std::cerr << "This position is not accessible!" << std::endl;
		return;

	}
		
	Node* prev = new(std::nothrow) Node();
	Node* curr = new(std::nothrow) Node();
	Node* temp = new(std::nothrow) Node();
	curr = frontPtr;
	
	for (size_t i = 1; i < pos; ++i) {

		prev = curr;
		curr = curr->nextPtr;
	
	}

	temp->data = newStudent;
	prev->nextPtr = temp;
	temp->nextPtr = curr;

}

void LinkedList::removeLast() {

	if (isEmpty()) {

		std::cerr << "The list is empty. You can not delete anything!" << std::endl;
		return;

	}

	Node* curr = new(std::nothrow) Node;
	Node* prev = new(std::nothrow) Node;
	curr = frontPtr;
	
	while (curr->nextPtr) {

		prev = curr;
		curr = curr->nextPtr;
	
	}
	
	backPtr = prev;
	prev->nextPtr = nullptr;
	--curSize;
	delete curr;

}

void LinkedList::removeFirst() {

	if (isEmpty()) {

		std::cerr << "The list is empty. You can not delete anything!" << std::endl;
		return;

	}

	Node *temp = new(std::nothrow) Node;
	temp = frontPtr;
	frontPtr = frontPtr->nextPtr;
	--curSize;
	delete temp;

}

void LinkedList::remove(size_t pos) {

	if (isEmpty() || pos > curSize) {

		std::cerr << "The list is empty or this position is not existing. You can not delete anything!" << std::endl;
		return;

	}

	Node* curr = new(std::nothrow) Node;
	Node* prev = new(std::nothrow) Node;
	curr = frontPtr;

	for (size_t i = 1; i < pos; ++i) {

		prev = curr;
		curr = curr->nextPtr;
	
	}

	prev->nextPtr = curr->nextPtr;

}

void LinkedList::print() {

	Node* front = this->frontPtr;

	while (front) {

		std::cout << "( " << front->data.getName() << ", " << front->data.getFacultyAsString() << " )";
		front = front->nextPtr;
		
		if (front)
			std::cout << " - ";

	}

	std::cout << std::endl;

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

bool LinkedList::isEmpty() {

	return curSize == 0;
	
}

bool LinkedList::isComparable(const Student & newStudent, size_t pos) {

	if (newStudent.getFaculty() == -1) {

		std::cerr << "This student is a spy! He is from other University!" << std::endl;
		return false;

	}
}