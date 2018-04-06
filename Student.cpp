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
//ostream &operator<<(ostream &os, Student const &student)
//{
//    return os << "ID# " << student.idNumber << " - " << student.firstName << ", " << student.lastName;
//}
void Student::printStudent()
{
    cout << "ID# " << idNumber << " - " << firstName << ", " << lastName << endl;
}
