
#include<stdio.h>
#include<stdlib.h>

int top = -1;

struct node
{
    int data;
    struct node *next;

}*head;

void push ()
{

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Stack Full. Pushing is not possible!");
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&newnode->data);
        newnode->next = head;
        head = newnode;
        printf("Item pushed\n");

    }
}

void pop()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
        printf("Item popped\n");

    }
}
void display()
{
    struct node *temp;
    temp=head;
    if(temp == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp ->next;
        }
    }
}



int main()
{
    int size,choice=0;
    printf("Enter the choice-1 to push .\n");
    printf("Enter the choice-2 to pop .\n");
    printf("Enter the choice-3 to display .\n");
    printf("Enter the choice-4 to exit .\n");

    while(choice!=4)
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Enter choice between 1-4. ");
        }

    }

    return 0;
}

