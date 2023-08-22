//mr-shakib

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*head,*temp;

void createlist(int n)
{
    struct node *newnode;
    head = (struct node*) malloc(sizeof(struct node));
    printf("Enter the value of the first node: ");
    scanf("%d",&head->data);
    head->next = NULL;
    temp=head;
    for(int i =1 ; i <n ; i++)
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter the value of node-%d: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
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






void DeleteFromBeg()
{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
}



int main()
{

    int n,pos,delPos;
    printf("Enter the number of elements of the list: ");
    scanf("%d",&n);
    createlist(n);
    display();

    DeleteFromBeg();
    display();


    return 0;
}




