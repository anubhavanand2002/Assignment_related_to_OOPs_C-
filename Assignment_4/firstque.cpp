#include<iostream>
#include<string.h>
using namespace std;
class vehicle{
protected:
int price;
char *name;//name  implies manufacturer name
public:
//Default constructor
vehicle()
{
    price=9000;
    const char*cn="suzuki";
    name=new char[strlen(cn)+1];
    strcpy(name,cn);
}
//Parametrized constructor 
vehicle(int p,char *c)
{
    price=p;
    name=new char[strlen(c)+1];
    strcpy(name,c);
}
//Copy constructor
vehicle(const vehicle &v)
{
    price=v.price;
    name=new char[strlen(v.name)+1];
    strcpy(name,v.name);
}
//Assignment operator
vehicle &operator=(const vehicle &q)
    {
        price=q.price;
        name=q.name;
        return *this;
    }
//Read data
int getprice()
{
    return price;
}
char* getname()
{
    return name;
}
//display data
void display()
{
    cout<<"The price is:"<<price<<"and the name is:"<<name<<"\n";
}
};

//inheritance of class car from class vehicle as public means-public value passed as public and protrcted value will paas as protected but private value will not pass
class car : public vehicle
{
  private:
  char *color;
  int number_of_seats;
  char *model;
  public:
  //Default constructor
  car():vehicle()
  {
      color="red";
      number_of_seats=5;
      model="latest";
  }
  //parametrized constructor
  car(char *co,int numseat,char *modl,int price,char *manufacturer):vehicle(price,manufacturer)
  {
    color=new char[strlen(co)+1];
    model=new char[strlen(modl)+1];
    strcpy(color,co);
    strcpy(model,modl);
    number_of_seats=numseat;
  }
  //Copy constructor
  car(const car &car2):vehicle(car2)
  {
    color=new char[strlen(car2.color)+1];
    model=new char[strlen(car2.model)+1];
    strcpy(color,car2.color);
    strcpy(model,car2.model);
    number_of_seats=car2.number_of_seats;
  }
  //Assignment operator
  car &operator=(const car &q)
    {
        vehicle::operator=(q);
        color=q.color;
        number_of_seats=q.number_of_seats;
        model=q.model;
        return *this;
    }
  //Read data
  int getnum_of_seat()
  {
      return number_of_seats;
  }
  char* getmodel()
  {
      return model;
  }
  char* getcolor()
  {
      return color;
  }
  //Display data
  void displaydata()
  {
      cout<<"The color of car is:"<<  color<<"and the number of seats in car is:"<<  number_of_seats<<"and the model of car is"<<  model<<"and price is"<<price<<"and manufacturer is:"<< name;
  }
  


};
int main()
{
    vehicle v1;
    v1.display();
    car c1;
    c1.displaydata();
    vehicle v(9999,"xyz");
    v.display();
    car c("Green",5,"suzuki",999,"abx");
    c.displaydata();

}