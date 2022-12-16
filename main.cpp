#include <iostream>
#include "roster.hpp"
using std::cout;
using std::string;
using std::endl;

int main()
{
    cout << "Name: Alexander Mammen\n\n";
    
   //using string to indentify student data and also allow for parsing
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Alexander,Mammen,2020amammen@gmail.com,21,20,20,40,SOFTWARE"
        };
    
    //once again, we need a constant for the number of students
    const int studentDataTable = 5;
    Roster roster;
        
    int i = 0;
    while (i < studentDataTable) {
        roster.parse(studentData[i]);
        i++;
    }
    //Display all students and data
    cout << "Displaying all students:\n";
    roster.printAll();
    cout << '\n';
    
    //displays all students who declare software as their major
    cout << "Displaying all software students:\n";
    roster.printByDegreeType(SOFTWARE);
    cout << '\n';

    //display all students with invalid email addresses
    cout << "Displaying invalid email addess:\n";
    roster.printInvalidEmails();
    cout << '\n';
    
    //display all average days per class for students
    cout << "Displaying average days per class:\n";
    for (int i = 0; i < studentDataTable; i++) {
        roster.printAverageDays(roster.classRosterArray[i]->getStuID());
    }
    cout << '\n';
    
    //remove student A3 and print all students
    cout << "Remove student A3.\n";
    roster.removeStudentByID("A3");
    cout << '\n';
    
    //include a "this student not found message" about student A3
    cout << "Remove student A3.\n";
    roster.removeStudentByID("A3");
    cout << '\n';
    

}


    
    

         


