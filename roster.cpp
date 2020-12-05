#pragma once
#include "roster.h"



void Roster::parse(string studentData) // Parse out each row individually
{
	DegreeProgram degreeprogram = SOFTWARE; //Default Value
	if (studentData.back() == 'E') degreeprogram = SOFTWARE;
	else if (studentData.back() == 'Y') degreeprogram = SECURITY;
	else if (studentData.back() == 'K') degreeprogram = NETWORK;

	int rhs = studentData.find(","); //finding the comma
	string studentID = studentData.substr(0, rhs); //extract the substring before the comma to find studentId

	int lhs = rhs + 1; // finding first name
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1; // finding last name
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1; // finding email
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1; //finding age
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs)); //First daysInCourse

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs)); //Second daysInCourse

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs)); //Third daysInCourse


	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);


}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int ndarr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 }; //Add daysInCourse into array
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, ndarr, degreeprogram);
	//Full Constructor
}

void Roster::printAll()
{
	Student::printHeader(); // print tab seperated list of student data
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getstudentID(); cout << '\t';
		cout << classRosterArray[i]->getfirstName(); cout << '\t';
		cout << classRosterArray[i]->getlastName(); cout << '\t';
		cout << classRosterArray[i]->getemailAddress(); cout << '\t';
		cout << classRosterArray[i]->getage(); cout << '\t';
		cout << classRosterArray[i]->getdaysInCourse()[0]; cout << '\t';
		cout << classRosterArray[i]->getdaysInCourse()[1]; cout << '\t';
		cout << classRosterArray[i]->getdaysInCourse()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;

	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) //print out student information for emunarated type
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmail() //verifies and displays invalid email addresses in student data table
{
	
	bool isValid = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sId = (classRosterArray[i]->getemailAddress());
		{
			if ((sId.find(".") == string::npos || sId.find("@") == string::npos) || (sId.find(" ") != string::npos))
			{
				isValid = true;
				cout << classRosterArray[i]->getstudentID() << ": " << sId << std::endl;
			}


			if (!isValid) cout << "NONE" << std::endl; }
	
	
	
		
	}
	
}

	

void Roster::printAveragedaysInCourse(string studentID) //prints a students average number of days in three courses
{
	
	for (int i = 0; i <= Roster::lastIndex; i++)  //loop to pass through array
	{
		
		if (classRosterArray[i]->getstudentID() == studentID) 
		cout << studentID << ": " << (classRosterArray[i]->getdaysInCourse()[0]
			+ classRosterArray[i]->getdaysInCourse()[1]
			+ classRosterArray[i]->getdaysInCourse()[2]) / 3.0 << std::endl;
	}
	cout << std::endl;
}

void Roster::removestudentByID(string studentID) //removes student from table based on ID number.
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getstudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << ": Student removed from roster." << std::endl << std::endl;
		this->printAll(); 
	}
	else cout << studentID << ": Student not found." << std::endl << std::endl; //generates error message "student not found"
}

Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl; //calls destructor to release dynamically allocated memory
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Removing student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
	 