#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
    cout << "First name: ";
    cin >> firstName;
    cout << endl << "Last name: ";
    cin >> lastName;
    cout << endl << "ID number: ";
    cin >> idNumber;
}
Student::Student(int id)
{
	idNumber = id;
}
ostream& operator << (ostream& os, Student const& student)
{
    os << "ID# " << student.idNumber << " - " << student.firstName << ", " << student.lastName;
	return os;
}

bool Student::operator < (const Student compare){ return idNumber < compare.idNumber;}
bool Student::operator > (const Student compare){ return idNumber > compare.idNumber;}
bool Student::operator <= (const Student compare){return !(idNumber > compare.idNumber);}
bool Student::operator >= (const Student compare){return !(idNumber < compare.idNumber);}
bool Student::operator == (const Student compare){return idNumber == compare.idNumber;}
bool Student::operator != (const Student compare){return !(idNumber == compare.idNumber);}
