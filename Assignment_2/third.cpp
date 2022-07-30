#include<iostream>
#include "third.h"
using namespace std;
// struct node
// {
//     string name;
//     struct node *next;
// };

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