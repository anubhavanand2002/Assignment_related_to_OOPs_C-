#include<iostream>
using namespace std;
struct node
{
    string name;
    struct node *next;
};
int chooser(int choose)
{
    int x;
    cout<<"Enter the value of variable:";
    cin>>x;
    switch(choose)
    {
    case 1:
    return((x*x)-(3*x)+1);
    case 2:
    return((x*x*x)-(7*x)+5);
    case 3:
    return((x*x)+1);
    }
   
}

string delet(struct node **head, int k)
{
    struct node *p = *head, *q = *head;
    int i;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        cout << p->name << " has been evicted.\n";
        free(p);
        p = q->next;
    }
    *head = p;

    return (p->name);
}

void create(struct node **head, int n)
{
    struct node *temp, *rear;
    string a;

    while (n--)
    {
        printf("Enter a name: ");
        cin >> a;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->name = a;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
    }
    rear->next = *head;
}

void print(struct node *head)
{
    struct node *temp;

    temp = head;
    cout << temp->name;
    temp = temp->next;
    while (head != temp)
    {
        cout << "   " << temp->name;
        temp = temp->next;
    }
    printf("\n");
}



int main()
{
    struct node *head = NULL;
    int skip, size;
    string winner;

    cout << "Enter the no of persons" << endl;
    cin >> size;

    int x;
    create(&head, size);
    printf("The persons in circular list are:\n");
    print(head);
    cout<<"Enter your choice:";
    cout<<"1.f(x)=(x*x)-(3*x)+1\n2.f(x)=(x*x*x)-(7*x)+5\n3.f(x)=(x*x)+1";
    int n;
    cin>>n;
    skip=chooser(n);
    winner = delet(&head, skip);
    cout << "The winner is : " << winner << endl;
    free(head);

    return 0;
}
