#include <iostream>
using namespace std;

class node
{
    public:
    string name;
    node *next;
};

class list
{
    private:
        node *head;
        int n;
        int k;
    public:
        void read()
        {
            head=NULL;
            cout<<"Enter the value of n"<<endl;
            cin>>n;
            cout<<"Enter the value of k"<<endl;
            cin>>k;
        }
        
void create()
{
    node *temp, *rear;
    string a;

    while (n--)
    {
        printf("Enter a name: ");
        cin >> a;
        temp = new node();
        temp->name = a;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
    }
    rear->next = head;
}



void display()
{
    node *temp;

    temp = head;
    cout << temp->name;
    temp = temp->next;
    while (head != temp)
    {
        cout << "   " << temp->name;
        temp = temp->next;
    }
    cout<<"\n";
}

string delet()
{
    node *p = head, *q = head;
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
    head = p;

    return (p->name);
}

};











int main()
{
    list q;
    q.read();
    int skip, size;
    string winner;

    // cout << "Enter the no of persons" << endl;
    // cin >> size;

    q.create();
    cout<<"The persons in circular list are:\n";
    q.display();
    winner = q.delet();
    cout << "The winner is : " << winner << endl;

    return 0;
}
