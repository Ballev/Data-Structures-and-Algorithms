#include <iostream>
#include "DynArr.h"


template<class T>
DynArr<T>::DynArr(size_t _size) : curSize(_size), cap(_size * 2) {

	if (cap <= size)
		resize();
	else
		arr = new(std::nothrow) T[cap];

}

template<class T>
DynArr<T>::DynArr() : arr(nullptr), curSize(0), cap(0)
{}

template<class T>
DynArr<T>::DynArr(const DynArr & other) {

	copyFrom(other);

}

template<class T>
DynArr & DynArr<T>::operator=(const DynArr & other) {

	if (this != &other) {

		copyFrom(other);

	}
	return *this;

}


template<class T>
DynArr<T>::~DynArr() {

	clean();

}

template<class T>
void DynArr<T>::pushback(const T & elem) {

	if (cap <= curSize)
		resize();
	arr[curSize++] = elem;

}

template<class T>
void DynArr<T>::removeLast() {

	if (curSize)
		--curSize;
	else
		throw std::length_error("already empty!");

}

template<class T>
void DynArr<T>::insertAt(const T & elem, size_t pos) {

	if (pos >= curSize)
		pushback(elem);
	else {
	
		++curSize;
		if (cap <= curSize)
			resize();

		for (size_t i = curSize - 1; i >= pos; --i) {

			arr[i] = arr[i - 1];
		
		}
		arr[pos] = elem;
	
	}

}

template<class T>
void DynArr<T>::removeAt(size_t pos) {

	if (pos >= curSize || curSize == 1)
		removeLast();
	else {
	
		for (size_t i = pos; i < curSize - 1; ++i) {

			arr[i] = arr[i + 1];
		
		}
		--curSize;
	
	}

}

template<class T>
const size_t DynArr<T>::getCurSize() const {

	return curSize;

}

template<class T>
const size_t DynArr<T>::getCap() const {

	return cap;

}

template<class T>
const T & DynArr<T>::operator[](size_t pos) const {

	if (pos >= curSize)
		throw std::out_of_range("out of range!!!");

	return arr[pos];

}

template<class T>
T & DynArr<T>::operator[](size_t pos) {

	return const_cast<T&>(static_cast<const DynamicArray&>(*this)[pos];);

}

template<class T>
int DynArr<T>::linearSearch(const T & elem) const {

	for (size_t i = 0; i < curSize; i++) {
		if (arr[i] == elem)
			return i;

	}

	return -1;

}

template<class T>
int DynArr<T>::binarySearch(const T & elem) const {

	size_t left = 0;
	size_t right = curSize;
	size_t middle = left + (right - left) / 2;
	while (left <= right) {

		if (arr[middle] > element) {

			right = middle - 1;
			middle = left + (right - left) / 2;

		}
		else if (arr[middle] < element) {

			left = middle + 1;
			middle = left + (right - left) / 2;

		}
		else 
			return middle;

	}

	return -1;

}

template<class T>
void DynArr<T>::selectionSort() {

	if (!arr || curSize == 0)
		return;

	for (size_t i = 0; i < curSize - 1; ++i) {

		size_t min = i;

		for (size_t j = i + 1; j < curSize; ++j) {

			if (arr[j] < arr[min])
				min = j;
		
		}

		if (arr[i] < arr[min])
			swap(arr[i], arr[min]);
	
	}

}

template<class T>
void DynArr<T>::bubbleSort() {

	if (!arr || curSize == 0)
		return;

	for (size_t i = 0; i < curSize - 1; ++i) {

		for (size_t j = curSize - 1; j > i; --j) {

			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);

		}

	}

}

template<class T>
void DynArr<T>::insertionSort() {

	if (!arr || curSize == 0)
		return;

	for (size_t i = curSize - 1; i > 0; --i) {
		
		if (arr[i] < arr[i - 1])
			swap(arr[i], arr[i - 1]);

	}

	for (size_t i = 2; i < curSize; ++i) {
		
		size_t j = i;

		while (arr[j - 1] > arr[i]) {

			arr[j] = arr[j - 1];
			--j;
		
		}

		arr[j] = arr[i];
	
	}

}

template<class T>
void DynArr<T>::print() {

	std::cout << "Array is: ";
	for (size_t i = 0; i < curSize; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

}

template<class T>
void DynArr<T>::clean() {

	delete[] arr;
	arr = nullptr;
	curSize = 0;
	cap = 0;

}

template<class T>
void DynArr<T>::resize() {

	if (curSize == 0) {

		cap = 1;

	}
	else {

		cap = 2 * curSize;

	}

	T* temp = new(std::nothrow) T[cap];
	for (size_t i = 0; i < size; ++i) {

		temp[i] = arr[i];

	}
	delete[] arr;
	arr = temp;

}

template<class T>
void DynArr<T>::copyFrom(const DynArr & other) {

	clean();
	arr = new(std::nothrow) T[other.cap];
	for (size_t i = 0; i < other.curSize; ++i) {

		arr[i] = other.arr[i]

	}
	curSize = other.curSize;
	cap = other.cap;

}

template<class T>
void DynArr<T>::swap(T & a, T & b) {

	T temp = a;
	a = b;
	b = a;

}

