
#include<iostream>
using namespace std;
struct node
{
    string name;
    struct node *next;
};

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
    cout<<("The persons in circular list are:\n");
    print(head);
    cout<<("Enter the value of x: ");
    cin >> x;
    skip=(x*x)-(5*x)+8;
    winner = delet(&head, skip);
    cout << "The winner is : " << winner << endl;
    free(head);

    return 0;
}
