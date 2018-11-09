#ifndef __STUDENT_HEADER__
#define __STUDENT_HEADER__

#include <string>
#include <iostream>
#include <fstream>

using std::string;

enum Faculty {

	FMI,
	TU,
	UNSS,
	UNDEFINED = -1

};

class Student {

public:

	Student();
	Student(const string, const Faculty&);

public:

	const string getName() const;
	const Faculty getFaculty() const;
	const string getFacultyAsString() const;
	void setName(const string);
	void setFaculty(const string&);

private:

	string name;
	Faculty university;

};


#endif //!__STUDENT_HEADER__
