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
ostream& operator << (ostream& os, Student const& student)
{
    os << "ID# " << student.idNumber << " - " << student.firstName << ", " << student.lastName;
	return os;
}

inline bool operator < (const Student& lhs, const Student& rhs){ return lhs.idNumber < rhs.idNumber;}
inline bool operator > (const Student& lhs, const Student& rhs){ return rhs < lhs;}
inline bool operator <= (const Student& lhs, const Student& rhs){return !(lhs > rhs);}
inline bool operator >= (const Student& lhs, const Student& rhs){return !(lhs < rhs);}
inline bool operator == (const Student& lhs, const Student& rhs){return lhs.idNumber == rhs.idNumber;}
inline bool operator != (const Student& lhs, const Student& rhs){return !(lhs == rhs);}
