#pragma once
#include "student.h"

Student::Student() //Empty constructor to set default values
{
	this->studentID = ""; //empty strings
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = age;

	for (int i = 0; i < NumDaysArraySize; i++) this->daysInCourse[i] = 0; 

	this->degreeprogram = DegreeProgram::SOFTWARE;
}
//parsing string data
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;

	for (int i = 0; i < NumDaysArraySize; i++) this->daysInCourse[i] = daysInCourse[i]; //For loop to set the number of days array

	this->degreeprogram = degreeprogram;
}

Student::~Student() {} // destructor

string Student::getstudentID() { return this->studentID; }
string Student::getfirstName() { return this->firstName; }
string Student::getlastName() { return this->lastName; }
string Student::getemailAddress() { return this->emailAddress; }
int Student::getage() { return this->age; }
int* Student::getdaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeprogram; }

void Student::setstudentID(string studentID) { this->studentID = studentID; }
void Student::setfirstName(string firstName) { this->firstName = firstName; }
void Student::setlastName(string lastName) { this->lastName = lastName; }
void Student::setemailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setage(int age) { age = age; }

void Student::setdaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < NumDaysArraySize; i++) this->daysInCourse[i] = daysInCourse[i]; 
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeprogram = degreeprogram; }

void Student::printHeader() //call to print header
{
	cout << "Output Format: StudentID|First Name|Last Name|Email Address|Age|Days In Course|Degree Program|\n";
}

void Student::print()
{
	cout << this->getstudentID() << '\t';
	cout << this->getfirstName() << '\t';
	cout << this->getlastName() << '\t';
	cout << this->getemailAddress() << '\t';
	cout << this->getage() << '\t';
	cout << this->getdaysInCourse()[0] << '\t';
	cout << this->getdaysInCourse()[1] << '\t';
	cout << this->getdaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';


}