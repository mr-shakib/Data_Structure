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
    int data;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack Full. Pushing is not possible!");
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&data);
        if(head==NULL)
        {
            temp->data = data;
            temp -> next = NULL;
            head=temp;
        }
        else
        {
            temp->data = data;
            temp->next = head;
            head=temp;

        }
        printf("Item pushed\n");

    }
}

void pop()
{
    int item;
    struct node *temp;
    if (head == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        item = head->data;
        temp = head;
        head = head->next;
        free(temp);
        printf("Item popped\n");

    }
}
void display()
{
    int i;
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
            temp = temp->next;
        }
    }
}



int main()
{
    int size,choice=0;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    int stack[size];

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
            push(stack,size);
            break;
        case 2:
            pop();
            break;
        case 3:
            display(stack);
            break;
        case 4:
            break;
        default:
            printf("Enter choice between 1-4. ");
        }

    }

    return 0;
}

