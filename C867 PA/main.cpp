/*
	Dylan Parson
	C867 Scripting and programming Applications
*/
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>

using namespace std;
void printMyInfo();

int main()
{
	// F. 1. Print out to the screen course title programming language wgu id and name
	printMyInfo();
	// F. 2. Create an intance of the Roster class called classRoster
	Roster classRoster = Roster();

	// Add each student to classRoster
	classRoster.fillTable();

	classRoster.printAll();
	classRoster.printInvalidEmails();


	for (int i = 0; i < classRoster.getClassSize(); i++) {
		classRoster.printAverageDaysInCourse(classRoster.getClassID(i));
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	// Create destructor
	classRoster.deleteArray();
}

void printMyInfo() {
	cout << "C867 Programming and Applications\t Written in C++\t Student ID: 010674532\t Name: Dylan Parson" << endl;
}