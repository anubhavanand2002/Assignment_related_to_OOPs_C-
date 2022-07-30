#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class Person
{
protected:
  char *name;
  int age;
  char *gender;

public:
Person() {}
  Person(char *name, int age, char *gender)
  {
    this->name = new char[strlen(name) + 1];
    this->gender = new char[strlen(gender) + 1];
    strcpy(this->name, name);
    strcpy(this->gender, gender);
    this->age = age;
  }
  void printGeneralData()
  {
    cout << "The name is " << name << endl;
    cout << "The age is " << age << endl;
    cout << "The gender is " << gender << endl;
  }
};

class Student : virtual public Person
{
  int year;

protected:
  char *dept;

public:
  Student(char *name, int age, char *gender, int year, char *dept) : Person(name, age, gender)
  {
    this->dept = new char[strlen(dept) + 1];
    strcpy(this->dept, dept);
    this->year = year;
  }

  Student(char *name, int age, char *gender, char *dept) : Person(name, age, gender)
  {
    this->dept = new char[strlen(dept) + 1];
    strcpy(this->dept, dept);
  }

  void printStudentData()
  {
    Person::printGeneralData();
    cout << "The department of the student is " << dept << endl;
    cout << "The year of the student is " << year << endl;
  }
  
  void printData() {
    Person::printGeneralData();
  }
};

class Clerk : virtual public Person
{
protected:
  char *workload;
  int salary;

public:
  Clerk(char *name, int age, char *gender, char *workload, int salary) : Person(name, age, gender)
  {
    this->workload = new char[strlen(workload) + 1];
    strcpy(this->workload, workload);
    this->salary = salary;
  }
  Clerk(char *workload, int salary)
  {
    this->workload = new char[strlen(workload) + 1];
    strcpy(this->workload, workload);
    this->salary = salary;
  }
  void printClerkData()
  {
    Person::printGeneralData();
    cout << "The workload of the clerk is " << workload << endl;
    cout << "The salary of the clerk is " << salary << endl;
  }
};

class Professor : public Student, public Clerk
{
public:
  Professor(char *name, int age, char *gender, char *dept, char *workload, int salary) : Student(name, age, gender, dept), Clerk(workload, salary) {}
  
  void printProfessorData()
  {
    Student::printData();
    // Person::printGeneralData();
    cout << "The department of the professor is " << dept << endl;
    cout << "The courseload of the professor is " << workload << endl;
    cout << "The salary of the professor is " << salary << endl;
  }
};

int main()
{
  Student obj1("anubhav",19,"male",2024,"cse");
  cout << "For Student:" << endl;
  obj1.printStudentData();
  cout << endl;

  Clerk obj2("vijay",19,"male","high",15000);
  cout << "For Clerk:" << endl;
  obj2.printClerkData();
  cout << endl;

  Professor obj3("ashish_sir",45,"male","cse","high",200000);
  cout << "For Professor:" << endl;
  obj3.printProfessorData();
  cout << endl;

  return 0;
}