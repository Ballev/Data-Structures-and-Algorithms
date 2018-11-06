#include "Student.h"



Student::Student() : name(nullptr), university(UNDEFINED)
{}

Student::Student(const string & _name, const Faculty & _university) : name(_name), university(_university)
{}

const string Student::getName() const {
	
	return name;

}

const Faculty Student::getFaculty() const {

	return university;

}
