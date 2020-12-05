#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
//using std::endl;

//Create student class for part D1
 
class Student
{
public:
	const static int NumDaysArraySize = 3; //declaring size of array for days in course
	
private: //Declaring student objects
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[NumDaysArraySize];
	DegreeProgram degreeprogram;

public:

	Student(); //parameterless constructor - sets to default vaules
	  
	//Full constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram);

	

	//Getters aka accessors
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int* getdaysInCourse();
	DegreeProgram getDegreeProgram();

	//Setters aka mutators
	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setdaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeprogram);

	static void printHeader(); //displays a header for the data to follow

	void print(); //displays student data

	~Student(); //Destructor
};

