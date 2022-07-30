

#include <iostream>
#include"third.h"
using namespace std;
int main()
{
    struct node *head = NULL;
    int skip, size;
    string winner;

    cout << "Enter the no of persons" << endl;
    cin >> size;

    create(&head, size);
    cout<<("The persons in circular list are:\n");
    print(head);
    printf("Enter the number of persons to be skipped: ");
    cin >> skip;
    winner = delet(&head, skip);
    cout << "The winner is : " << winner << endl;
    free(head);

    return 0;
}