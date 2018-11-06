#ifndef __STUDENT_HEADER__
#define __STUDENT_HEADER__

#include <string>
#include <iostream>

using std::string;

enum Faculty {

	FMI,
	TU,
	UNWE,
	UNDEFINED = -1

};

class Student {

public:

	Student();
	Student(const string&, const Faculty&);

public:

	const string getName() const;
	const Faculty getFaculty() const;

private:

	string name;
	Faculty university;

};

#endif //!__STUDENT_HEADER__
