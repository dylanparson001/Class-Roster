#pragma once
#include "student.h"
#ifndef roster
#define roster

class Roster {
	int classSize = 5;
	// Array of pointers
	Student *classRosterArray = new Student[classSize];

	const string  studentData[5] = { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
					"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
					"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
					"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
					// A.  Modify the “studentData Table” to include your personal information as the last item.
					"A5,Dylan,Parson,dylan.parson001@gmail.com,27, 20,30,40,SOFTWARE" };
public:
	Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void fillTable();
	int getClassSize();
	string getClassID(int index);
	Student parseData(int studentIndex);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void remove(string studentID);
	void deleteArray();
};
#endif // !roster
