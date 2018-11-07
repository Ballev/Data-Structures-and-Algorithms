#include <iostream>
#include <string>

#include "DynamicArray.h"
#include "Student.h"
#include "LinkedList.h"
#include "Helper.h"

using std::string;


int main() {

	string input = "af fa asf asf a aa aas da da";
	//std::cin >> input;
	LinkedList list;
	Student ivan; 
	ivan.setName("Ivan");
	std::cout << wordCnt(input) << std::endl;
	return 0;

}