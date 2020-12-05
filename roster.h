#pragma once
#include "student.h"
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	

public:
	Student* classRosterArray[numStudents];

	void parse(string row); //parsing table data to class

	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram); //adding all table data to Roster class

	void printAll(); //Calls print method for each student

	void printByDegreeProgram(DegreeProgram degreeprogram); // Degree type passed in

	void printInvalidEmail(); //Prints Invalid Email Addresses

	void printAveragedaysInCourse(string studentID); //Prints the average days in course of all students

	void removestudentByID(string studentID); //Removes student by ID number

	~Roster(); //destructor call
};



