#include<iostream>
#include<fstream>
using namespace std;
struct student{
char name[50];
int age;
char department[50];
char year[50];
};
void ReadStudentData(struct student *p)
{
  cout<<"Enter name:"<<endl;
  cin>>(p->name);
  cout<<"Enter age:"<<endl;
  cin>>(p->age);
  cout<<"Enter department:"<<endl;
  cin>>(p->department);
  cout<<"Enter year:"<<endl;
  cin>>(p->year);

}


void PrintStudentData(struct student *a)
{
    cout<<"name="<<a->name<<"\nage="<<a->age<<"\ndepartment="<<a->department<<"\nyear="<<a
    ->year<<endl;
}





int main(){
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
struct student s[n];
for(int i=0;i<n;i++)
{
  ReadStudentData(&s[i]);
}

for(int i=0;i<n;i++)
{
    PrintStudentData(&s[i]);
}
return 0;
}

