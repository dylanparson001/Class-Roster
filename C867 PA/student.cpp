#include <string>
#include <iostream>
#include "student.h"

void Student::setID(int ID) {
	Student::studentID = ID;
}

void Student::setFirstName(string name) {
	firstName = name;
}

void Student::setLastName(string name) {
	lastName = name;
}

void Student::setEmail(string email) {
	emailAddress = email;
}

void Student::setDays(int newDays[]) {
	for (int i = 0; i < 3; i++) {
		daysForCourse[i] = newDays[i];
	}
}

void Student::setAge(int newAge) {
	age = newAge;
}

void Student::setDegree(DegreeProgram prog) {
	program = prog;
}
// e. print() to print specific student data
void Student::print() {
	cout << endl << this->getID() << "\t"
		<< this->getFirstName() << "\t"
		<< this->getLastName() << "\t"
		<< this->getEmail() << "\t"
		<< this->getAge() << "\t"
		<< *this->getDays(0) << "\t"
		<< *this->getDays(1) << "\t" 
		<< *this->getDays(2) << "\t"
		<< this->getDegree() << endl;
}
/* D.  For the Student class, do the following:
*/

//1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables :
//•  student ID
//	•  first name
//	•  last name
//	•  email address
//	•  age
//	•  array of number of days to complete each course
//	•  degree program


//2.  Create each of the following functions in the Student class :
//	a.an accessor(i.e., getter) for each instance variable from part D1
//	b.a mutator(i.e., setter) for each instance variable from part D1
//	c.All external accessand changes to any instance variables of the Student class must be done using accessorand mutator functions.
//	d.constructor using all of the input parameters provided in the table
//	e.print() to print specific student data
// Constructor
//Student::Student(string ID, string first, string last, string email, int studentAge, int days[], DegreeProgram prog) {
//
//};
// Getters and Setters