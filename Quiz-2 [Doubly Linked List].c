#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head,*temp;

void createList(int arr, int size)
{
    struct node *newnode;
    head = (struct node*) malloc(sizeof (struct node));
    printf("Enter the value of node - 1 : ");
    scanf("%d",&head->data);
    head->prev = NULL;
    head->next = NULL;
    temp = head;
    for (int i = 1; i < size; ++i)
    {
        newnode = (struct node*) malloc(sizeof (struct node));
        printf("Enter the value of node - %d : ",i+1);
        scanf("%d",&newnode->data);
        newnode->prev = temp;
        newnode->next = NULL;
        temp->next=newnode ;
        temp = newnode;
    }

}

void insertByPosition(int pos)
{
    struct node *newnode, *temp;
    temp = head;
    for (int i = 1; i < pos-1; ++i)
    {
        temp = temp->next;
    }
    newnode = (struct node*) malloc(sizeof (struct node));
    printf("Enter the value of new node : ");
    scanf("%d",&newnode->data);
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    if(newnode->next != NULL)
    {
        newnode->next->prev = newnode;
    }
}

int searchElement(struct node *head,int value)
{
    struct node *temp;
    int index = 0;
    temp = head;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            return index;
        }
        temp = temp->next;
        index++;

    }
    return -1;
}


void deleteFromEnd()
{
    struct node *temp,*del;
    temp=head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    del = temp->next;
    temp->next = NULL;
    free(del);
}

void display(int arr[],int size)
{
    int count = 0;
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        count++;
        printf("Value %d = %d\n",count, temp->data);
        temp = temp->next;
    }


}


int main()
{

    int size,pos;
    printf("Enter the size of the List : ");
    scanf("%d",&size);
    int arr[size];
    createList(arr,size);
    display(arr,size);
    printf("Enter the position you want to add new node : ");
    scanf("%d",&pos);
    insertByPosition(pos);
    display(arr,size);
    int value;
    printf("Enter the value you want to find : ");
    scanf("%d",&value);
    int index = searchElement(head,value);
    if(index == -1){
        printf("%d was not found in the list.\n",value);
    }else{
    printf("%d was found at position %d\n",value, index+1);
    }

    deleteFromEnd();
    display(arr,size);


}
