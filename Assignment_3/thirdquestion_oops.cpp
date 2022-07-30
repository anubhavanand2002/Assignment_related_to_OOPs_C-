#include<iostream>
using namespace std;
template <typename T>
class growingstack
{
    int size;
    int maxSize;
    T *arr;

public:
    int top;
    // constructor
    growingstack(int &size)
    {
        top = -1;
        size = size;
        arr = new T[size];
    }

    // destructor
    // ~growingstack()
    // {
    //     free(arr);
    // }

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
        arr = (T *)realloc(arr, (currentSize() + 1) * sizeof(T));
        size++;
    }

    // Empty checking function
    int isEmpty()
    {
        return (top == -1);
    }

    void push(T num)
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

    T pop()
    {
        T a = arr[top--];
        return a;
    }

    growingstack &operator=(const growingstack &);
};



int main()
{
    // for stack 1
    cout << "Enter the maximum size of the stack1" << endl;
    int N1;
    cin>>N1;
    int n1;
    cout << "Enter the initial size of the stack1" << endl;
    cin >> n1;
    growingstack<char>s1(n1);
    s1.getMaxSize(N1);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n1; i++)
    {
        char c;
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
        char p;
        cin>>p;
        s1.push(p);
    }
    cout << "Popped elements of stack 1:\n";
    while (s1.top != -1)
        cout << s1.pop() << endl;


//
// for stack 1
    cout << "Enter the maximum size of the stack1" << endl;
    int N2;
    cin>>N2;
    int n2;
    cout << "Enter the initial size of the stack1" << endl;
    cin >> n2;
    growingstack<int>s2(n2);
    s1.getMaxSize(N2);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n2; i++)
    {
        int c;
        cin >> c;
        s2.push(c);
    }
    // int a1=5,a2=6,a3=7;
    // s1.push(a1);
    // s1.push(a2);
    // s1.push(a3);
    cout<<"Initial size is full,now it is inflated so enter according to left size:";
    for(int i=n2;i<N2;i++)
    {
        int p;
        cin>>p;
        s2.push(p);
    }
    cout << "Popped elements of stack 1:\n";
    while (s2.top != -1)
        cout << s2.pop() << endl;



    return 0;
}
