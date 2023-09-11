#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head,*temp;

void createlist(int n)
{
    struct node *newnode;
    head = (struct node*) malloc(sizeof(struct node));
    printf("Enter the value of the first node: ");
    scanf("%d",&head->data);
    head->prev = NULL;
    head->next = NULL;
    temp=head;
    for(int i =1 ; i <n ; i++)
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter the value of node-%d: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev = temp;
        temp->next=newnode;
        temp=newnode;
    }
}


void InsertByPosition(int pos)
{
    struct node *newnode, *temp;
    temp = head;
    for(int i = 1 ; i < pos-1 ; i++)
    {
        temp = temp->next;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of position-%d : ",pos);
    scanf("%d",&newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    if(newnode->next!=NULL){
        newnode->next->prev = newnode;
    }
}

void display()
{
    int count = 0;
    struct node *temp;
    temp=head;
    printf("Display list : \n");
    while(temp!=NULL)
    {
        count++;
        printf("Value-%d = %d\n",count,temp->data);
        temp=temp->next;
    }

}

int main()
{
    int n,pos,delPos,delValue;
    printf("Enter the number of elements of the list: ");
    scanf("%d",&n);
    createlist(n);
    display();


    printf("Enter the position you want to add : ");
    scanf("%d",&pos);
    InsertByPosition(pos);
    display();


    return 0;

}
