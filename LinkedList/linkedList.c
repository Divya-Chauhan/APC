#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * head=NULL;

void insertBeg(int data, struct node **head)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}


void insertPos(int data , int pos, struct node **head)
{
	struct node *temp=(struct node *) malloc(sizeof(struct node));
	int i=1;
	struct node *curr = *head;
	
	while(i<pos-1 && curr)
	{
		curr=curr->next;
		i++;
	}
	
	if(curr)
	{
		temp->data=data;
		temp->next=curr->next;
		curr->next=temp;
	}
	else
		printf("\ninvalid position\n");
		
}
	
void delAtBeg(struct node **head)
{
	struct node *temp;
	if(*head)
	{
		temp=*head;
		*head=(*head)->next;
		free(temp);
	}

}
	
void delAtPos(struct node **head, int pos)
{
	int i=1;
	struct node * curr=*head;
	struct node * temp;
	while(i<pos-1&&curr)
	{
		curr=curr->next;
		i++;
	}
	if(curr->next)
	{
		temp=curr->next;
		curr=temp->next;
		free(temp);
	}

}



void delAtEnd(struct node **curr)
{
	struct node * head=*curr;
	if((*curr)->next==NULL)
	{
		free(*curr);
		*curr=NULL;
	}
	else
	{
		while(head->next&&head->next->next)
			head=head->next;
		
		free(head->next);
		head->next=NULL;
	}
}

void insertEnd(int data, struct node **head)
{
	struct node *temp=(struct node *) malloc (sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node *curr = *head;
	
	if(*head == NULL)
		*head = temp;
	else
	{
		while(curr->next)
			curr=curr->next;
		curr->next=temp;
	}
}


void list_p(struct node *current)
{
	while(current->next)
	{
		printf("%d\t",current->data);
		current=current->next;
	}
	printf("%d\t",current->data);
}



int main()
{
	int value;
	int n;
	
	scanf("%d",&n);
	
	while(n)
	{
		scanf("%d",&value);
		insertEnd(value,&head);
		n--;
	}
	
	printf("enter pos\n");
	scanf("%d",&n);
	insertPos(50,n,&head);
	printf("Enter pos to delete and current list is :\n");
	list_p(head);
	scanf("%d",&n);
	
	while(n&&head)
	{
		delAtPos(&head,n);
		printf("list is : \n");
		if(head)
		list_p(head);
		printf("Enter 1 to delete and 0 to exit");
		scanf("%d",&n);
	}
	
	if(head)
		list_p(head);
	return 0;
}


