#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};


int main()
{
    struct node *node1,*node2,*node3;

    node1 = (struct node*)malloc(sizeof(struct node));
    node2 = (struct node*)malloc(sizeof(struct node));
    node3 = (struct node*)malloc(sizeof(struct node));

    node1->data = 5;
    node1->next = node2;
    node1->prev = NULL;

    node2->data = 10;
    node2->prev = node1;
    node2->next = node3;

    node3->data = 15;
    node3->prev = node2;
    node3->next = NULL;

    printf("Value of node-1 = %d\n",node1->data);
    printf("Value of node-2 = %d\n",node2->data);
    printf("Value of node-3 = %d\n",node3->data);


    return 0;
}