#include <string>
#include <iostream>
#include "roster.h"
using namespace std;

// Constructor
Roster::Roster() {

}
//E. 3. A. public void add() that sets instance variable fsfrom part D1 and updates the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	bool isNewRoster = false;

	Student* tempArray = new Student[classSize];
	// putting old roster into temp
	for (int i = 0; i < classSize; i++) {
		tempArray[i] = classRosterArray[i];
	}
	classSize += 1;
	// resizing array
	classRosterArray = new Student[classSize];

	for (int i = 0; i < classSize - 1; i++) {
		classRosterArray[i] = tempArray[i];
	}
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	Student newStudent = Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
	classRosterArray[classSize - 1] = newStudent;
};


void Roster::fillTable() {
	// 2. Create a student object for each student in the data tale and populate classRoster
	for (int i = 0; i < classSize; i++) {
		Student temp;
		temp = parseData(i);
		classRosterArray[i] = temp;
	}
}
string Roster::getClassID(int index) {
	return classRosterArray[index].getID();
}
int Roster::getClassSize() {
	return classSize;
}

// 2. a. Parse each set of data identified in the student data table
Student Roster::parseData(int studentIndex) {
	// Parsing string process
	string delimiter = ",";
	size_t pos = 0;
	string token;
	string studentInfo[9];
	auto start = 0U;
	auto end = studentData[studentIndex].find(delimiter);
	int counter = 0;
	while (end != string::npos) {
		studentInfo[counter] = studentData[studentIndex].substr(start, end - start);
		start = end + delimiter.length();
		end = studentData[studentIndex].find(delimiter, start);
		counter++;
	}
	// last bit of data parsed
	studentInfo[8] = studentData[studentIndex].substr(start, end);

	// stores age as an int
	int studentAge = stoi(studentInfo[4]);

	// int array for days left in courses
	int daysLeft[3];
	int daysIndex = 5;
	for (int i = 0; i < 3; i++) {
		daysLeft[i] = stoi(studentInfo[daysIndex]);
		daysIndex++;
	}

	// degree program variable assignment based on data
	DegreeProgram program = SECURITY; // Default value

	if (studentInfo[8] == "SECURITY") {
		program = SECURITY;
	}
	else if (studentInfo[8] == "SOFTWARE") {
		program = SOFTWARE;

	}
	else if (studentInfo[8] == "NETWORK") {
		program = NETWORK;
	}
	string studentID = studentInfo[0];
	string studentFirst = studentInfo[1];
	string studentLast = studentInfo[2];
	string studentEmail = studentInfo[3];

	Student newStudent = Student(studentID, studentFirst, studentLast, studentEmail, studentAge, daysLeft, program);
	return newStudent;
}

void Roster::printAll() {
	for (int i = 0; i < classSize; i++) {
		classRosterArray[i].print();
	}
}
// E. 3. d. correctly prints a students average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentID) {
	bool foundID = false;
	int index = 0; // keeps track of index when student is found
	int totalDays = 0; 
	int averageDays = 0;
	int totalClasses = 3;
	// Search through array
	for (int i = 0; i < classSize; i++) {
		// compare studentIDs to input
		if (classRosterArray[i].getID() == studentID) {
			foundID = true;
			index = i;
			break; // gets out of loop when index is found
		}
	}

	// if match isnt found, output error message and do nothing
	if (foundID == false) {
		cout << "Sorry, Id was not found" << endl;
	}
	else {
		for (int i = 0; i < totalClasses; i++) {
			totalDays += *classRosterArray[index].getDays(i);
		}
		int averageDays = totalDays / totalClasses;

		cout << "This student has average days: " << averageDays << endl;
	}
};
// E. 3. f. prints out student information to a degree program specified by an enumurated type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < classSize; i++) {
		if (degreeProgram == classRosterArray[i].getDegreeProgram()) {
			classRosterArray[i].print();
		}
	}
}
// E. 3. e. Verifies student emails and displays all invalid email addresses to the user
void Roster::printInvalidEmails() {
	string at = "@";
	string period = ".";
	string space = " ";

	for (int i = 0; i < classSize; i++) {
		string email = classRosterArray[i].getEmail();
		if (email.find(at) == string::npos || email.find(period) == string:: npos || email.find(space) != string::npos) {
			cout << classRosterArray[i].getEmail() << endl;
		}
	}
}
// E. 3. B. public void remove (string studentID) that removes students from roster by studentID, if ID does not exist the function prints an error message
void Roster::remove(string studentID) {
	bool foundID = false;
	int index = 0; // keeps track of index when student is found

	// Search through array
	for (int i = 0; i < classSize; i++) {
		// compare studentIDs to input
		if (classRosterArray[i].getID() == studentID) {
			foundID = true;
			index = i;
			break; // gets out of loop when index is found
		}
	}

	// if match isnt found, output error message and do nothing
	if (foundID == false) {
		cout << "Sorry, Id was not found" << endl;
	}
	// If it matches, remove that students 
	else {
		cout << endl << "Student found, Deleting now... " << endl;
		// If element is already the last in array
		Student* tempArray = new Student[classSize];

		if (index == classSize - 1) {
			classSize -= 1;
			for (int i = 0; i < classSize; i++) {
				tempArray[i] = classRosterArray[i];
			}
			classRosterArray = new Student[classSize];
			for (int i = 0; i < classSize; i++) {
				classRosterArray[i] = tempArray[i];
			}
		}
		// If element is elsewhere in array
		else {
			// Reorganize array so that the element being removed is last
			for (int i = index; i < classSize - 1; i++) {
				classRosterArray[i] = classRosterArray[i + 1];
			}
			classSize -= 1;
			for (int i = 0; i < classSize; i++) {
				tempArray[i] = classRosterArray[i];
			}
			classRosterArray = new Student[classSize];
			for (int i = 0; i < classSize; i++) {
				classRosterArray[i] = tempArray[i];
			}
		}
	}
}
void Roster::deleteArray() {
	delete[] classRosterArray;
}