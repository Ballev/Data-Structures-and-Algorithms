#include "Helper.h"

size_t strlen(const string & input) {

	size_t len = 0, i = 0;
	while (input[i++]) {

		++len;

	}

	return len;

}

// Assuming correct input is given.
 const size_t wordCnt(const string & input) {

	size_t words = 1, i = 0;
	while (input[i] != '\0') {

		if (input[i] == ' ')
			++words;
	
		++i;
	
	}

	return words;

}

void useInput(const string& input) {

	DynamicArray arr;
	LinkedList queue;
	Student s;
	size_t wordsNumber = wordCnt(input);
	size_t inputLen = strlen(input);
	string* tempWords = new string[wordsNumber];
	string tempWord;
	size_t i = 0, j = 0, k = 0;

	do {

		do {

			tempWord[k] = input[i];
			
			++i;
			++k;
			
			if(input[i] == ' ') {
			
				tempWords[j++] = tempWord;
				k = 0;
				std::cout << tempWords[j - 1] << "  " << tempWord << std::endl;

			}

		} while (input[i]);

		if (tempWords[0] == "print") {
			arr.print();

		}

		else if (tempWords[0] == "merge") {

			size_t casted1 = std::stoi(tempWords[1]);
			size_t casted2 = std::stoi(tempWords[2]);

			//.mergeQueues(casted1, casted2);

		}

		else if (tempWords[0] == "remove") {
			
			size_t casted = std::stoi(tempWords[2]);
			arr.removeAt(tempWords[1], casted);

		}

		else if (tempWords[0] == "removeFirst") {

			size_t casted = std::stoi(tempWords[1]);
			arr.removeFirst(casted);
		
		}

		else if (tempWords[0] == "removeLast") {

			size_t casted = std::stoi(tempWords[1]);
			arr.removeLast(casted);

		}

		else if (tempWords[0] == "append") {

			Student s;
			s.setName(tempWords[1]);
			s.setFaculty(tempWords[2]);

			size_t casted = std::stoi(tempWords[3]);
			//arr.append(s, casted);

		}

	} while (tempWords[0] != "quit");

}