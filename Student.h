#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
using namespace std;

struct Student
{
    char lastName[20];
    char firstName[20];
    int idNumber;
    
    Student();
	bool operator == (const Student);
	bool operator > (const Student);
	bool operator < (const Student);
	
	friend ostream& operator << (ostream &stream, const Student &student);
};

#endif
