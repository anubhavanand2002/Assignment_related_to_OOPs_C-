#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
struct GrowingStack
{
    int top;
    T *arr;
    int size;
    int maxsize;
};
template<typename T>
struct GrowingStack<T> *initialize(int n, int N)
{
    struct GrowingStack<T> *MyStack = (struct GrowingStack<T> *)malloc(sizeof(struct GrowingStack<T>));
    MyStack->top = -1;
    MyStack->size = n;
    MyStack->maxsize = N;
    MyStack->arr = (T*)malloc(n * sizeof(T));

    return MyStack;
}

int getMaxSize()
{
    int n;
    cin >> n;
    return n;
}

template<typename T>
int currentSize(struct GrowingStack<T> *MyStack)
{
    return MyStack->top + 1;
}
template<typename T>
void inflate(struct GrowingStack<T> *MyStack)
{
    MyStack->arr = (T *)realloc(MyStack->arr, (currentSize(MyStack) + 1) * sizeof(T));
    MyStack->size++;
}

template<typename T>
int isEmpty(struct GrowingStack<T> *MyStack)
{
    return MyStack->top == -1;
}

template<typename T>
void push(struct GrowingStack<T> *MyStack, T num)
{
    if (currentSize(MyStack) >= MyStack->maxsize)
    {
        cout << "Stack has reached its maximum limit" << endl;
        return;
    }
    else if (MyStack->top == currentSize(MyStack) - 1)
    {
        inflate(MyStack);
    }
    MyStack->top++;
    MyStack->arr[MyStack->top] = num;
}
template<typename T>
T pop(struct GrowingStack<T> *MyStack)
{
    T a = MyStack->arr[MyStack->top--];
    return a;
}

int main()
{
    // for stack 1
    cout << "Enter the maximum size of the stack1" << endl;
    int N1 = getMaxSize();
    int n1;
    cout << "Enter the initial size of the stack1" << endl;
    cin >> n1;
    struct GrowingStack<int> *stack1 = initialize<int>(n1, N1);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n1; i++)
    {
        int c;
        cin >> c;
        push<int>(stack1, c);
    }
    push<int>(stack1, 5);
    push<int>(stack1, 4);
    push<int>(stack1, 6);
    while (stack1->top != -1)
        cout << pop<int>(stack1) << endl;


    return 0;
}