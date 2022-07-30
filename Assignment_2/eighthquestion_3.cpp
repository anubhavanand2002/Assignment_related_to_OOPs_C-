#include<iostream>
using namespace std;
struct node
{
    string name;
    struct node *next;
};
void reverse(struct node** head_ref)
{
    if (*head_ref == NULL)
        return;
 
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (*head_ref));
 
    (*head_ref)->next = prev;
    //*head_ref = prev;
}
string survivor(struct node **head, int k)
{
    if(k<0)
    {
        k=-k;
        reverse(head);
    }
    
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

void display(struct node *head)
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
    display(head);
    printf("Enter the value of x: ");
    cin >> x;
    winner = survivor(&head, x);
    cout << "The winner is : " << winner << endl;
    free(head);

    return 0;
}