#pragma once
#include "roster.h"

int main()
{
	 const string studentData[] = //Student data parsed 
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erikson,Erikson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Balck,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jeffrey,Gall,Jeffreysgall@gmail.com,37,17,25,48,SOFTWARE"
	};

	const static int numStudents = 5;
	Roster classRoster; // create instance of Roster named classRoster


	cout << "\n"; 
	cout << "Course title: C867 - Scripting and Programming Applications" << "\n"; //course title
	cout << "Language used: C++" << "\n"; //language
	cout << "Student ID: 001085808" << "\n"; //student ID
	cout << "Name: Jeffrey Gall"<< "\n"; //my name
	cout << "\n";
	cout << "\n";

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students: " << std::endl;

	classRoster.printAll(); 
	cout << std::endl;


	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by Degree Program: " << degreeProgramStrings[i] << std::endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}
	 

	cout << "Displaying students with invalid Emails: " << std::endl;
	classRoster.printInvalidEmail();
	cout << std::endl;

	cout << "Displaying average number of days in course: " << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		string studentID = classRoster.classRosterArray[i]->getstudentID();
		classRoster.printAveragedaysInCourse(studentID);
	}
	cout << "Removing student with ID A3: " << std::endl;
	classRoster.removestudentByID("A3");
	cout << std::endl;

	cout << "Removing student with ID A3: " << std::endl;
	classRoster.removestudentByID("A3");
	cout << std::endl;

	system("pause"); //press any key for destructor
	return 0;
	
};