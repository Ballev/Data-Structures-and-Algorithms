#include <iostream>
#include <string>

#include "DynamicArray.h"
#include "Student.h"
#include "LinkedList.h"
#include "Helper.h"

using std::string;

int main() {

	string input = "add Ivan FMI";
	//std::cin >> input;
	LinkedList list;
	DynamicArray arr;
	Student a, b, c;
	a.setName("Georgi");
	a.setFaculty("FMI");
	b.setName("Ivan");
	b.setFaculty("UNSS");
	c.setName("Pesho");
	c.setFaculty("TU");

	list.addAtBeg(a);
	list.addAtEnd(b);
	list.addAtBeg(c);
	arr.add(list);
	std::cout << arr.getCurSize() << std::endl;
	arr.print();
	//useInput(input);
	return 0;

}