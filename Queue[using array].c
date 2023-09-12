#include <stdio.h>
#include<stdlib.h>

int top = -1;

void push(int stack[], int size)
{
    top++;
    if(top==size)
    {
        printf("Stack Full. Pushing is not possible!");
        top--;//as here no data inserted. display (0-top)
    }
    else
    {

        printf("Enter the value you want to insert : ");
        scanf("%d",&stack[top]);

    }
    printf("Item pushed!\n");

}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top--;
    }
}

void display(int stack[])
{
    printf("Printing Stack elements \n");
    for(int i = top ; i>=0 ; i--)
    {
        printf("%d\n",stack[i]);
    }
    if(top == -1)
    {
        printf("Stack is empty.\n");
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
        switch(choice){
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
        printf("Enter choice between 1-4. \n");
        }

    }

    return 0;
}