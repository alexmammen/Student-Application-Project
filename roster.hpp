#pragma once
#ifndef Roster_hpp
#define Roster_hpp
#include <stdio.h>
#include "student.hpp"

class Roster
{
public:
    //this allows for easier access with parsing
    int lastIndex=-1;
    const static int studentDataTable = 5;
    Student* classRosterArray[studentDataTable];
    
public:
    //created to seperate date by comma
    void parse(string row);
   //creating add method
    void add(string sID,
             string stuFirstName,
             string stuLastName,
             string stuEmailADD,
             int stuAge,
             int day1,
             int day2,
             int day3,
             DegreeType dt);
    //methods in which most of user seen output will be called through
    void printAll();//prints every student
    void printByDegreeType(DegreeType dt);//prints students by their degree type
    void printInvalidEmails();//needs @ and . and cannot have spaces
    void printAverageDays(string studentID);//average days in course by the students
    bool removeStudentByID(string studentID);//removes student by ID number
    
    //Destructor
    ~Roster();
    
};


#endif
