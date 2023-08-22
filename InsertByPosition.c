
//mr-shakib

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp;

void createList(int n)
{
    struct node *newnode;

    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of node-1 : ");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value of node-%d : ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
}

void InsertByPosition(int pos)
{
    struct node *newnode;

    temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of new node at position-%d : ",pos);
    scanf("%d",&newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void displayList()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        printf("Value of node - %d  = %d\n", count, temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, pos;
    printf("Enter the numebr of elements of the list : ");
    scanf("%d", &n);
    createList(n);
    displayList();
    printf("Enter the position you want to add data : ");
    scanf("%d", &pos);
    InsertByPosition(pos);
    displayList();

    return 0;
}

