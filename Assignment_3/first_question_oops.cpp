#include<iostream>
using namespace std;
class student{
private:
int age;
string department;
string name;
int year;
public:
void Readstudentsdata(int age,string department,string name,int year);

void printstudentsdata();

};

void student::Readstudentsdata(int age,string department,string name,int year)
{
   this->age=age;
   this->department=department;
   this->year=year;
   this->name=name;
}
void student::printstudentsdata()
{
    cout<<"name="<<this->name<<endl;
    cout<<"age="<<this->age<<endl;
    cout<<"department="<<this->department<<endl;
    cout<<"year="<<this->year<<endl;
}









int main()
{
    int n;
    cin>>n;
    student s[n];
    string name,department;
    int age,year;
    for(int i=0;i<n;i++)
    {
      cout<<"Enter name:"<<endl;
      cin>>name;
      cout<<"Enter age:"<<endl;
      cin>>age;
      cout<<"Enter department"<<endl;
      cin>>department;
      cout<<"Enter year:"<<endl;
      cin>>year;
      s[i].Readstudentsdata(age,department,name,year);
    }
    for(int i=0;i<n;i++)
    {
        s[i].printstudentsdata();
    }
  return 0;
}