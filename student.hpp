#pragma once
#ifndef student_hpp
#define student_hpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.hpp"
using std::cout;
using std::string;

class Student
{
public:
    //Define a constant array of days
    const static int daysArray = 3;
//private variables that are only called within this file
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[daysArray];
    DegreeType degreeType;

public:
    //Constructor
    Student();
    Student(string studentID, string firstName, string lastName, string emailAdd, int age, int days[], DegreeType degreeType);
    ~Student();//destructor
    
    //Create accessors(getters) so private variables can be indirectly called
    string getStuID();
    string getFirstName();
    string getLastName();
    string getEmailAdd();
    int getAge();
    int* getDays();
    DegreeType getDegreeType();
    
    //Create mutators(setters) so private variables can be set
    void setStuID(string studentID);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmailAdd(string emailAdd);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeType(DegreeType dt);;
    
    //create header for main
    static void printHeader();
    
    //allows us to print data
    void print();
};



#endif 
