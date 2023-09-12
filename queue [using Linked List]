#include<stdio.h>
#include<stdlib.h>

int top = -1;

struct node
{
    int data;
    struct node *next;

}*front,*rear,*temp;


void enqueue (int queue[], int size)
{
    int data;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Queue Full. Inserting is not possible!");
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&data);
        temp->data = data;
        if(front==NULL)
        {
            front = temp;
            rear = temp;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = NULL;

        }
        printf("Item inserted\n");

    }
}

void dequeue()
{
    int item;
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;
        front = front->next;
        printf("Item deleted:%d \n",temp->data);
        free(temp);
    }
}
void display(int queue)
{
    int i;
    struct node *temp;
    temp=front;
    if(temp == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Printing Queue elements \n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}



int main()
{
    int size,choice=0;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    int queue[size];

    printf("Enter the choice-1 to insert .\n");
    printf("Enter the choice-2 to delete .\n");
    printf("Enter the choice-3 to display .\n");
    printf("Enter the choice-4 to exit .\n");

    while(choice!=4)
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue(queue,size);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display(queue);
            break;
        case 4:
            break;
        default:
            printf("Enter choice between 1-4. ");
        }

    }

    return 0;
}

