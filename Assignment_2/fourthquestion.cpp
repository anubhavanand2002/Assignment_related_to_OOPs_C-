#include <iostream>
// template <class T>
template <typename T>
void swap(T &first,T &second){
     T temp = first;
    first = second;
    second = temp;
}
 
struct s{
  int p;
  int q;
 }s;
int main()
{
    std::cout<<"Please enter type of data to swap\n:";
    std::cout<<"Enter 1 for int\n";
    std::cout<<"Enter 2 for float\n";
    std::cout<<"Enter 3 for char\n";
    std::cout<<"Enter 4 for struct\n";
    std::cout<<"Enter 5 for double\n";
    int c;
    std::cin>>c;
    switch(c)
    {
    case 1:
    int a,b;
    std::cin>>a>>b;
    swap<int>(a,b);
    std::cout << a << " " << b<<"\n";
    break;
    case 2:
    float c,d;
    std::cin>>c>>d;
    swap<float>(c,d);
    std::cout << c << " " << d<<"\n";
    break;
    case 3:
    char l,m;
    std::cin>>l>>m;
    swap<char>(l,m);
    std::cout << l << " " << m<<"\n";
    break;
    case 4:
    s.p=9;
    s.q=5;
    swap(s.p,s.q);
    std::cout<<s.p<<" "<<s.q<<"\n";
    break;
    case 5:
    double e,f;
    std::cin>>e>>f;
    swap<double>(e,f);
    std::cout<<e<<" "<<f<<"\n";
    break;
    default:
    std::cout<<"Your choice is wrong:";

    }
    return 0;
}