#include <string>
#include <iomanip>
#include "roster.hpp"

//defining parse method by allowing it to "parse" through each row of data
void Roster::parse(string studentrows)
{
    //find comma
    int rhs = studentrows.find(',');
    //acquire substring following
    string sID = studentrows.substr(0, rhs);
    
    //move past comma
    int lhs = rhs + 1;
    //find the following comma
    rhs = studentrows.find(',', lhs);
    //this data will be the first name
    string stuFirstName = studentrows.substr(lhs, rhs - lhs);
    
    //move past comma
    lhs = rhs + 1;
    rhs = studentrows.find(',', lhs);
    //this data will be the last name
    string stuLastName = studentrows.substr(lhs, rhs - lhs);
    
    //move past comma
    lhs = rhs + 1;
    rhs = studentrows.find(",", lhs);
    //this data will be the student's email address
    string stuEmailAdd = studentrows.substr(lhs, rhs - lhs);
    
    //move past comma
    lhs = rhs + 1;
    rhs = studentrows.find(",", lhs);
    //this data will be the student's age
    int stuAge = stoi(studentrows.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentrows.find(",", lhs);
    //this data will be the first set of days
    int day1 = stod(studentrows.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1; //continue
    rhs = studentrows.find(",", lhs);
    //this data will be the second set of days
    int day2 = stod(studentrows.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1; //continue
    rhs = studentrows.find(",", lhs);
    //this data will be the third set of days
    int day3 = stod(studentrows.substr(lhs, rhs-lhs));
    
    
    lhs = rhs + 1;
    rhs = studentrows.find(",", lhs);

    //Finding which degreetype the student is in. Using a simple method by finding first letter of the data, if it is unique than apply that data to dt, if it is not unique find the next letter until you have a unique set of chars
    DegreeType dt  = SECURITY;
    
    if (studentrows.at(lhs) == 'S' && studentrows.at(lhs+1) == 'E') dt = SECURITY;
    else if (studentrows.at(lhs) == 'S' && studentrows.at(lhs+1) == 'O') dt = SOFTWARE;
    else if (studentrows.at(lhs) == 'N') dt = NETWORK;
    
    add(sID, stuFirstName, stuLastName, stuEmailAdd, stuAge, day1, day2, day3, dt);

}

//define add method
void Roster::add(string studentID, string firstName, string lastName, string emailAdd, int age, int day1, int day2, int day3, DegreeType dt)
{
    //creating array for sets of days in course
    int darr[3] = {day1, day2, day3};
    //use prefix ++ because we started with -1 for the index
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAdd, age, darr, dt);
}

//defining print all to display all students
void Roster::printAll()
{
    Student::printHeader();
    //for loop throught the roster to return the data for each student
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

//defining invalid emails method to display all invalid emails
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i<=Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmailAdd());
        
        if (!(email.find("@") != string::npos && email.find(" ") == string::npos && email.find(".") != string::npos))
        {
            any = true;
            cout << email << ":" << classRosterArray[i]->getFirstName() << std::endl;
        }
    }
    //print NONE if no invalid emails
    if (!any) cout << "NONE" << std::endl;
}

//defining print average days method by adding the 3 sets of values and dividing by 3.0
void Roster::printAverageDays(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStuID()==studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0]+
                     classRosterArray[i]->getDays()[1]+
                     classRosterArray[i]->getDays()[2])/3.0 << std::setprecision(3) << std::endl;
        }
    }
}

//defining print by degree type method
void Roster::printByDegreeType(DegreeType dt)
{
    Student::printHeader();
    int i = 0;
    while (i <= Roster::lastIndex) {
        if (Roster::classRosterArray[i]->getDegreeType() == dt) {
            Roster::classRosterArray[i]->print();
        }
        i++;
    }
    cout << std::endl;
}

//defining removestudentbyid method
bool Roster::removeStudentByID(string studentID)
{
    //best practice to assume false
    bool success = false;
    for (int i=0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStuID() == studentID)
        {
            //student found
            success = true;
            if (i < studentDataTable - 1)
            {
                //using pointer to replace the student and hide them in memory; not necessarily 'delete' them
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentDataTable - 1];
                classRosterArray[studentDataTable - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " was removed from roster." << std::endl << std::endl;
        //print the rest of the students
        this->printAll();
    }
    else cout << studentID << " This student is not found." << std::endl << std::endl;;
    return 0;
}
//destructor to remove dynamically created memory
Roster::~Roster()

{
    cout << "Destructor called!" << std::endl << std::endl;
    for (int i=0; i < studentDataTable; i++)
        //usually wouldn't call anything after destructor is called but we are doing so for 'educational purposes'
    {
        cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
