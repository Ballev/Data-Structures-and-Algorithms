#include "Student.h"


Student::Student() : name(""), university(UNDEFINED)
{}

Student::Student(const string _name, const Faculty & _university) : name(_name), university(_university)
{}

const string Student::getName() const {
	
	return name;

}

const Faculty Student::getFaculty() const {

	return university;

}

const string Student::getFacultyAsString() const {

	if (university == 0)
		return "FMI";
	
	else if (university == 1)
		return "TU";
	
	else if (university == 2)
		return "UNSS";
	
	else {

		std::cerr << "Western spy! Not allowed here!" << std::endl;
		return "";

	}
}

void Student::setName(const string _name) {

	name = _name;

}
