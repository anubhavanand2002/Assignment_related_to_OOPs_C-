#ifndef THIRD_H
#define THIRD_H
struct node
{
    std::string name;
    struct node *next;
};

std::string delet(struct node **head, int k);

void create(struct node **head, int n);


void print(struct node *head);

#endif




