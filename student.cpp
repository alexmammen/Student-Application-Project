#include "student.hpp"
using std::endl;
//create a parameterless constructor to initialize values
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysArray; i++) this->days[i] = 0;
    //sets default degreetype
    this->degreeType = DegreeType::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAdd, int age, int days[], DegreeType degreeType)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this-> email = emailAdd;
    this->age = age;
    for (int i = 0; i < daysArray; i++) this->days[i] = days[i];
    this ->degreeType = degreeType;
}
//No actual need for constructor since nothing here is dynamically created
Student::~Student() {}

//Defining getters from header file
string Student::getStuID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmailAdd() {return this->email;}
int Student::getAge() {return this->age;}
int* Student::getDays() {return this->days;}
DegreeType Student::getDegreeType() {return this->degreeType;}

//Defining setters from header file
void Student::setStuID(string studentID) {this->studentID = studentID;}
void Student::setFirstName(string fName) {this->firstName = fName;}
void Student::setLastName(string lName) {this->lastName = lName;}
void Student::setEmailAdd(string email) {this->email = email;}
void Student::setAge(int age) {this->age = age;}
void Student::setDays(int days[])
{
    for (int i = 0; i < daysArray; i++) this -> days[i] = days[i];
}
void Student::setDegreeType(DegreeType dt){this ->degreeType = dt;}

//Here are the contents of the header
void Student::printHeader()
{
    cout << "ID : First Name : Last Name : Email Address : Age : Days to Complete Course : Degree" << endl;
}
//Contents of print function
void Student::print()
{
    cout << this->getStuID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAdd() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeTypeStrings[this->getDegreeType()] << '\n';
}
