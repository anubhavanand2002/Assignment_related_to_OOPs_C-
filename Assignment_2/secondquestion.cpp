#include <iostream>
#include <cstdlib>
using namespace std;

struct GrowingStack
{
    int top;
    int *arr;
    int size;
    int maxsize;
};

struct GrowingStack *initialize(int n, int N)
{
    struct GrowingStack *newStack = (struct GrowingStack *)malloc(sizeof(struct GrowingStack));
    newStack->top = -1;
    newStack->size = n;
    newStack->maxsize = N;
    newStack->arr = (int *)malloc(n * sizeof(int));

    return newStack;
}

int getMaxSize()
{
    int a;
    cin >> a;
    return a;
}

int currentSize(struct GrowingStack *newStack)
{
    return newStack->top + 1;
}

struct GrowingStack *inflate(struct GrowingStack *newStack)
{
    newStack->arr = (int *)realloc(newStack->arr, (currentSize(newStack) + 1) * sizeof(int));
    newStack->size++;
    return newStack;
}

int isEmpty(struct GrowingStack *newStack)
{
    return newStack->top == -1;
}

void push(struct GrowingStack *newStack, int num)
{
    if (currentSize(newStack) >= newStack->maxsize)
    {
        cout << "Stack has reached its maximum limit" << endl;
        return;
    }
    else if (newStack->top == ((newStack->size) - 1))
    {
        inflate(newStack);
    }
    newStack->top++;
    newStack->arr[newStack->top] = num;
}

int pop(struct GrowingStack *newStack)
{
    int a = newStack->arr[newStack->top--];
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
    struct GrowingStack *stack1 = initialize(n1, N1);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n1; i++)
    {
        int c;
        cin >> c;
        push(stack1, c);
    }
    cout<<"Now initial size is full but you can enter upto max size of the stack:";
    for(int i=n1;i<N1;i++)
    {
    int c;
    cin>>c;
    push(stack1, c);
    }
    cout<<"Stack overflow now:";
    while (stack1->top != -1)
        cout << pop(stack1) << endl;

    // for stack 2
    cout << "Enter the maximum size of the stack2" << endl;
    int N2 = getMaxSize();
    int n2;
    cout << "Enter the initial size of the stack2" << endl;
    cin >> n2;
    struct GrowingStack *stack2 = initialize(n2, N2);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n2; i++)
    {
        int c;
        cin >> c;
        push(stack2, c);
    }
    cout<<"Now initial size is full but you can enter upto max size of the stack:";
    for(int i=n2;i<N2;i++)
    {
    int d;
    cin>>d;
    push(stack2, d);
    }
    cout<<"Stack overflow now:";
    
    while (stack2->top != -1)
        cout << pop(stack2) << endl;

     // for stack 1
    cout << "Enter the maximum size of the stack4" << endl;
    int N4 = getMaxSize();
    int n4;
    cout << "Enter the initial size of the stack4" << endl;
    cin >> n4;
    struct GrowingStack *stack4 = initialize(n4, N4);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n4; i++)
    {
        int c;
        cin >> c;
        push(stack4, c);
    }

    cout << "Enter the maximum size of the stack5" << endl;
    int N5 = getMaxSize();
    int n5;
    cout << "Enter the initial size of the stack5" << endl;
    cin >> n5;
    struct GrowingStack *stack5 = initialize(n5, N5);
    cout << "Push the initial elements" << endl;
    for (int i = 0; i < n5; i++)
    {
        int c;
        cin >> c;
        push(stack5, c);
    }

    struct GrowingStack *stack6 = initialize(n4 + n5, N5 + N5);
    while (stack4->top != -1 && stack5->top != -1)
    {
        push(stack6, pop(stack5));
        push(stack6, pop(stack4));
    }
    while (stack4->top != -1)
        push(stack6, pop(stack4));
    while (stack5->top != -1)
        push(stack6, pop(stack5));

    while (stack6->top != -1)
        cout << pop(stack6) << endl;

    return 0;
    return 0;
}