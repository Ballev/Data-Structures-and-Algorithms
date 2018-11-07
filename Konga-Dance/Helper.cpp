#include "Helper.h"

// Assuming correct input is given.
size_t wordCnt(const string & input) {

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
	string tempWord;
	size_t i = 0;

	do {


		--wordsNumber;
	} while (wordsNumber);

	do {

		if (tempWord == "print") {
			arr.print();

		}

		else if (tempWord == "merge") {



		}

		else if (tempWord == "remove") {
			
			//queue.remove();

		}

		else if (tempWord == "removeFirst") {


		}

		else if (tempWord == "removeLast") {


		}

		else if (tempWord == "append") {


		}

	} while (tempWord != "quit");
}