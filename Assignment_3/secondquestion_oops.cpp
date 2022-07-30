#include <iostream>
using namespace std;
class growingstack
{
    int size;
    int maxSize;
    int *arr;
    static int count;
public:
    int top;
    // constructor
    growingstack(int &size)
    {
        count+=1;
        top = -1;
        size = size;
        arr = new int[size];
    }

    // destructor
    ~growingstack()
    {
        delete []arr;
        cout<<"Destructor called";
    }

    // setmax function
    void getMaxSize(int &n)
    {
        maxSize = n;
    }

    // currentsize function
    int currentSize()
    {
        return top + 1;
    }

    void inflate()
    {
        arr = (int *)realloc(arr, (currentSize() + 1) * sizeof(int));
        size++;
    }

    // Empty checking function
    int isEmpty()
    {
        return (top == -1);
    }

    void push(int num)
    {
        if (currentSize() >= maxSize)
        {
            cout << "Stack has reached its maximum limit" << endl;
            return;
        }
        else if (top == size - 1)
        {
            inflate();
        }
        top++;
        arr[top] = num;
    }

    int pop()
    {
        int a = arr[top--];
        return a;
    }
    // copy constructor
    growingstack(growingstack &s)
    {
        this->size=4;
        for(int i=0;i<4;i++)
        {
            int x=s.pop();
           this->arr[top++]=x;
        }
    }


    growingstack &operator=(const growingstack &);
};
int growingstack::count=0;
growingstack &growingstack::operator=(const growingstack &rhs)
{
    if(this==&rhs)
    return *this;
    int length = rhs.top + 1;
    arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = rhs.arr[i];
    }
    size = rhs.size;
    maxSize = rhs.maxSize;
    top=rhs.top;
    return *this;
}

int main()
{
    // for stack 1
    cout << "Enter the maximum size of the stack1" << endl;
    int N1;
    cin>>N1;
    int n1;
    cout << "Enter the initial size of the stack1" << endl;
    cin >> n1;
    growingstack s1(n1);
    s1.getMaxSize(N1);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n1; i++)
    {
        int c;
        cin >> c;
        s1.push(c);
    }
    // int a1=5,a2=6,a3=7;
    // s1.push(a1);
    // s1.push(a2);
    // s1.push(a3);
    cout<<"Initial size is full,now it is inflated so enter according to left size:";
    for(int i=n1;i<N1;i++)
    {
        int p;
        cin>>p;
        s1.push(p);
    }
    cout << "Popped elements of stack 1:\n";
    while (s1.top != -1)
        cout << s1.pop() << endl;

  // for stack 2
    cout << "Enter the maximum size of the stack2" << endl;
    int N2;
    cin>>N2;
    int n2;
    cout << "Enter the initial size of the stack2" << endl;
    cin >> n2;
    growingstack s2(n2);
    s2.getMaxSize(N2);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n2; i++)
    {
        int c;
        cin >> c;
        s2.push(c);
    }
    // s2.push(15);
    // s2.push(34);
    // s2.push(26);
    cout<<"Initial size is full,now it is inflated so enter according to left size:";
    for(int i=n2;i<N2;i++)
    {
        int q;
        cin>>q;
        s2.push(q);
    }
    cout << "Popped elements of stack 2:\n";
    while (s2.top != -1)
        cout << s2.pop() << endl;

    // for stack 4
    cout << "Enter the maximum size of the stack4" << endl;
    int N4;
    cin>>N4;
    int n4;
    cout << "Enter the initial size of the stack4" << endl;
    cin >> n4;
    growingstack s4(n4);
    s4.getMaxSize(N4);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n4; i++)
    {
        int c;
        cin >> c;
        s4.push(c);
    }
    cout<<"Initial size is full,now it is inflated so enter according to left size:";
    for(int i=n4;i<N4;i++)
    {
        int r;
        cin>>r;
        s4.push(r);
    }

    // for stack 5
    cout << "Enter the maximum size of the stack5" << endl;
    int N5;
    cin>>N5;
    int n5;
    cout << "Enter the initial size of the stack5" << endl;
    cin >> n5;
    growingstack s5(n5);
    s5.getMaxSize(N5);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n5; i++)
    {
        int c;
        cin >> c;
        s5.push(c);
    }
    cout<<"Initial size is full,now it is inflated so enter according to left size:";
    for(int i=n5;i<N5;i++)
    {
        int t;
        cin>>t;
        s1.push(t);
    }
    
    int n6=n4+n5;
    int N6=N4+N5;
    growingstack s6(n6);
    s6.getMaxSize(N6);
    while (s4.top != -1 && s5.top != -1)
    {
        s6.push(s5.pop());
        s6.push(s4.pop());
    }
    while (s4.top != -1)
        s6.push(s4.pop());
    while (s5.top != -1)
        s6.push(s5.pop());

    cout << "Popped elements of stack 6:\n";
    while (s6.top != -1)
        cout << s6.pop() << endl;


    // copy_contructor
     int d=4;
     growingstack norm(d);
     int d1=6;
     norm.getMaxSize(d1);
     for(int i=0;i<4;i++)
     {
         norm.push(i);
     }
     growingstack copy(norm);
     cout<<"Elements in copy contructor are:"<<endl;
     for(int i=0;i<4;i++)
     {
         cout<<copy.pop()<<endl;
     }
     
     cout<<endl<<endl;
    // Assignment operator
     growingstack cr1(d);
     cr1.getMaxSize(d1);
     for(int i=0;i<4;i++)
     {
         cr1.push(i);
     }
    growingstack new2(d);
    new2 = cr1;
    for (int i = 0; i < 4; i++)
    {
        cout << new2.pop() << endl;
    }

    return 0;
}