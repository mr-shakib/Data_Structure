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


void DeleteByPosition(int pos){
    struct node *temp,*prev;
    temp = head;
    for(int i = 1 ; i < pos ; i++){
        prev = temp;
        temp = temp->next;

    }
    prev->next = temp->next;
    free(temp);


}


int main()
{

    int n,pos,delPos;
    printf("Enter the number of elements of the list: ");
    scanf("%d",&n);
    createlist(n);
    display();


    printf("Enter what position you want to add your data : ");
    scanf("%d",&delPos);
    DeleteByPosition(delPos);
    display();

    return 0;
}




