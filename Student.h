#ifndef STUDENTS_H
#define STUDENTS_H

struct Student
{
    char lastName[20];
    char firstName[20];
    int idNumber;
    
    Student();
    void printStudent();
};

#endif
