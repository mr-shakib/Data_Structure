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

int linearSearch(struct node *head, int item){
    struct node *current = head;
    int index = 0;
     while (current != NULL)
    {
      if (current->data == item)
	{
	  return index;
	}
      current = current->next;
      index++;
    }
  return -1;
}


int main()
{

    int n;
    printf("Enter the number of elements of the list: ");
    scanf("%d",&n);
    createlist(n);
    display();

    int item;
    printf("Enter the value you want to find: ");
    scanf("%d",&item);

    int index = linearSearch (head, item);

  if (index == -1)
    printf ("Item not found");
  else
    printf ("Item found at position: %d", index + 1);


    return 0;
}




