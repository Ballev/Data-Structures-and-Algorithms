#pragma once

template<class T>
class DynArr {

public:
	DynArr();
	DynArr(size_t);
	DynArr(const DynArr&);
	DynArr& operator=(const DynArr&);
	~DynArr();

public:
	void pushback(const T&);
	void removeLast();
	void insertAt(const T&, size_t);
	void removeAt(size_t);
	const size_t getCurSize() const;
	const size_t getCap() const;

public:
	const T& operator[](size_t) const;
	T& operator[](size_t);

	int linearSearch(const T&) const;
	int binarySearch(const T&) const;
	
	void selectionSort();
	void bubbleSort();
	void insertionSort();
	void print();

private:
	void clean();
	void resize();
	void copyFrom(const DynArr &other);
	void swap(T&, T&);

private:
	T* arr;
	size_t curSize;
	size_t cap;
};

