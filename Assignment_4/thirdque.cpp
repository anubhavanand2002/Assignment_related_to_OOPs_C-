// //METHOD 1

// #include<iostream>
// #include<string.h>
// using namespace std;
// class Shape {
//    protected:
//       int width, height;
      
//    public:
//       Shape( int a, int b){
//          width = a;
//          height = b;
//       }
//       int area(int c) {
//          return(c*width*height);
//       }
// };
// class Rectangle: public Shape {
//    public:
//       Rectangle( int a, int b):Shape(a, b) { }
// };

// class Triangle: public Shape {
//    public:
//       Triangle( int a, int b):Shape(a, b) { }
// };

// class circle: public Shape {
//    public:
//       circle( int a, int b):Shape(a, b) { }
// };
// int main()
// {
//     int n1,n2,n3;
//     cout<<"Enter number of shapes in your plots which are rectangle,triangle,and circle";
//     cin>>n1>>n2>>n3;
//     cout<<"Enter length and bredth of rectangle:";
//     int l,br;
//     cin>>l>>br;
//     Rectangle r1(l,br);
//     cout<<"Enter the base and height of your triangle:";
//     int b,h;
//     cin>>b>>h;
//     Triangle t1(b,h);
//     cout<<"Enter the radius of your circle:";
//     int r;
//     cin>>r;
//     circle c1(r,r);
//     int a1,a2,a3,total;
//     a1=r1.area(1);
//     a2=t1.area(1/2);
//     a3=c1.area(3.14);
//     total=(n1*a1)+(n2*a2)+(n3*a3);
//     cout<<"The total area of your plot is:"<<total<<"\n";

// }


// //METHOD 2


// #include <iostream>
// using namespace std;

// #include <ctime>
// #include <cstdlib>

// class Shape
// {
// public:
//     virtual void read() = 0;
//     virtual double calc_area() = 0;
// };

// class Triangle : public Shape
// {
//     double base;
//     double height;

// public:
//     Triangle() : base(0), height(0) {}
//     Triangle(const double given_base, const double given_height) : base(given_base), height(given_height) {}
//     double calc_area()
//     {

//         return 0.5 * base * height;
//     }
//     void read();
// };

// void Triangle::read()
// {
//     cout << "Enter Base: ";
//     cin >> base;
//     cout << "Enter Height: ";
//     cin >> height;
// }

// class Rectangle : public Shape
// {
//     double length;
//     double breadth;

// public:
//     Rectangle() : length(0), breadth(0) {}
//     Rectangle(const double given_length, const double given_breadth) : length(given_length), breadth(given_breadth) {}
//     double calc_area()
//     {
//         return length * breadth;
//     }

//     void read();
// };
// void Rectangle::read()
// {
//     cout << "Enter Length: ";
//     cin >> length;
//     cout << "Enter Breadth: ";
//     cin >> breadth;
// }

// const double pi = 3.14159;

// class Circle : public Shape
// {
//     double radius;

// public:
//     Circle() : radius(0) {}
//     Circle(const double given_radius) : radius(given_radius) {}
//     double calc_area()
//     {
//         return pi * radius * radius;
//     }
//     void read();
// };

// void Circle::read()
// {
//     cout << "Enter Radius: ";
//     cin >> radius;
// }

// int main()
// {
//     srand(time(0));

//     float sum_area = 0;
//     int counter = 0;
//     int num_rand;

//     Shape *shape_ptr[10];

//     num_rand = rand() % 2 + 1;

//     for (int i = counter; i < counter + num_rand; i++)
//     {
//         shape_ptr[i] = new Triangle(rand() % 10 + 1, rand() % 10 + 1);
//         sum_area += shape_ptr[i]->calc_area();
//     }

//     counter += num_rand;

//     num_rand = rand() % 2 + 1;

//     for (int i = counter; i < counter + num_rand; i++)
//     {
//         shape_ptr[i] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1);
//         sum_area += shape_ptr[i]->calc_area();
//     }

//     counter += num_rand;

//     for (int i = counter; i < 10; i++)
//     {
//         shape_ptr[i] = new Circle(rand() % 10 + 1);
//         sum_area += shape_ptr[i]->calc_area();
//     }

//     cout << "Sum of Areas: " << sum_area << endl;
//     return 0;
// }


//Another Method 3

#include <math.h>

#include <iostream>
using namespace std;

const double PI = 3.14;

class Shape {
   public:
    static double totalArea;
    virtual void updateArea() = 0;
    static void displayArea() { cout << "AREA of total land containing triangle,rectngle and circle is: " << totalArea << "\n"; }
};

double Shape::totalArea = 0;

class Triangle : public Shape {
    double base,height;

   public:
    Triangle() : base(0), height(0) {}
    Triangle(double s1, double s2) : base(s1), height(s2) {}

    void updateArea() {
        double area = 1/2*base*height;
        Shape::totalArea += area;
    }
};

class Rectangle : public Shape {
    double length, breadth;

   public:
    Rectangle() : length(0), breadth(0) {}
    Rectangle(double l, double b){
       length=l;
       breadth=b;
    }

    void updateArea() {
        double area = length * breadth;
        Shape::totalArea += area;
    }
};

class Circle : public Shape {
    double Radius;

   public:
    Circle() : Radius(0) {}
    Circle(double radius) : Radius(radius) {}

    void updateArea() {
        double area = PI * Radius * Radius;
        Shape::totalArea += area;
    }
};

int main() {
    Shape::displayArea();

    Triangle t1(3, 3);
    t1.updateArea();
    Shape::displayArea();
    Rectangle r1(4, 5);
    r1.updateArea();
    Shape::displayArea();

    Circle c1(4);
    c1.updateArea();

    Shape::displayArea();
    return 0;
}
