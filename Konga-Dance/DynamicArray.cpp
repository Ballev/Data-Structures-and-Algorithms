#include "DynamicArray.h"


DynamicArray::DynamicArray() : arr(nullptr), curSize(0), cap(0)
{}

DynamicArray::DynamicArray(const queue & newQueue) : curSize(1), cap(2) {

	arr = new(std::nothrow) queue[cap];

	if (!arr) {

		std::cerr << "Problem with allocating memory!" << std::endl;
		return;
	
  }

	arr[0] = newQueue;

}

DynamicArray::DynamicArray(const DynamicArray & other) {

	copyFrom(other);

}

DynamicArray & DynamicArray::operator=(const DynamicArray & other) {

	if (this != &other) {

		copyFrom(other);

	}

	return *this;

}

DynamicArray::~DynamicArray() {

	clean();

}

void DynamicArray::add(const queue & newQueue) {

	if (cap <= curSize)
		resize();

	arr[curSize++] = newQueue;

}

void DynamicArray::removeLast() {

	if (curSize)
		--curSize;
	else
		std::cerr << "Already empty!" << std::endl;

}

void DynamicArray::insertAt(const queue & newQueue, size_t pos) {

	if (pos >= curSize)
		add(newQueue);

	else {

		if (cap <= curSize)
			resize();

		for (size_t i = curSize; i > pos; --i) {

			arr[i] = arr[i - 1];

		}

		arr[pos] = newQueue;
		++curSize;

	}
}

void DynamicArray::removeAt(size_t pos) {

	if (pos >= curSize || curSize == 1)
		removeLast();
	else {

		for (size_t i = pos; i < curSize - 1; ++i) {

			arr[i] = arr[i + 1];

		}

		--curSize;

	}
}

const size_t DynamicArray::getCurSize() const {

	return curSize;

}

void DynamicArray::print() {

	for (size_t i = 0; i < curSize; ++i) {

		std::cout << "Line" << i << ": ";
		arr[i].print();

	}
}

void DynamicArray::clean() {

	delete[] arr;
	curSize = 0;
	cap = 0;
	arr = nullptr;

}

void DynamicArray::resize() {

	if (curSize == 0) 
		cap = 1;
	else 
		cap = 2 * curSize;

	queue* temp = new(std::nothrow) queue[cap];
	
	if (!temp) {

		std::cerr << "Problem with allocating memory!" << std::endl;
		return;
	
  }

	for (size_t i = 0; i < curSize; ++i) {

		temp[i] = arr[i];

	}

	delete[] arr;
	arr = temp;

}

void DynamicArray::copyFrom(const DynamicArray & other) {

	clean();
	arr = new(std::nothrow) queue[other.cap];
	
	if (!arr) {

		std::cerr << "Problem with allocating memory!" << std::endl;
		return;

	}

	for (size_t i = 0; i < other.curSize; ++i) {

		arr[i] = other.arr[i];

	}
	
	curSize = other.curSize;
	cap = other.cap;

}
