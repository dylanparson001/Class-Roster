#pragma once
#include "degree.h"
#include "string"
#ifndef student
#define student

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysForCourse[3];
	DegreeProgram program;

public:
	Student() {
		studentID = "0";
		firstName = "0";
		lastName = "0";
		emailAddress = "0";
		// Tried to do in for loop, wont work for some reason.
		daysForCourse[0] = 0;
		daysForCourse[1] = 0;
		daysForCourse[2] = 0;
		age = 50000;
		program = SOFTWARE;
	};
	Student(string ID, string first, string last, string email, int studentAge, int days[], DegreeProgram prog) {
		studentID = ID;
		firstName = first;
		lastName = last;
		emailAddress = email;
		// Tried to do in for loop, wont work for some reason.
		daysForCourse[0] = days[0];
		daysForCourse[1] = days[1];
		daysForCourse[2] = days[2];
		age = studentAge;
		program = prog;
	};
	string getID() {
		return studentID;
	}
	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}
	string getEmail() {
		return emailAddress;
	}
	int* getDays(int index) {
		return &daysForCourse[index];
	}
	int getAge() {
		return age;
	}
	DegreeProgram getDegreeProgram() {
		return program;
	}
	string getDegree() {
		switch (this->program) {
		case 0:
			return "SECURITY";
			break;
		case 1:
			return "SOFTWARE";
			break;
		case 2:
			return "NETWORK";
			break;
		}
	}
	void print();

	void setID(int ID);

	void setFirstName(string name);

	void setLastName(string name);

	void setEmail(string email);

	void setDays(int newDays[]);

	void setAge(int newAge);

	void setDegree(DegreeProgram prog);

};
#endif // !student.h



/* D.  For the Student class, do the following:

1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
•  student ID
•  first name
•  last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program

2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data */

