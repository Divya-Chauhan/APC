/*
Print the reverse of linked list using recursion
Verify if a Linked list is a palindrome or not using recursion 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node * next;	
}node;

node *head = NULL;

void reverse1(node *curr)
{
	if(curr==NULL)
		return ;
	else
	{
		//printf("%d\t",curr->data);
		reverse1(curr->next)	;
		printf("%d\t",curr->data);
	
	}

}

int ispalindrome(node *h, node *curr)
{
	int r, res;
	
	if(curr == NULL)
		return 1;
	
	else
	{
	
		res=ispalindrome(h, curr->next);
		
		if(res == 0)
			return 0;
		
		r = h->data == curr->data;
		h = h->next;
		 
		return r;
	}
}



void delete_pos(node **h, int pos)
{
	int i;
	node * temp;
	if(*h==NULL )
	{
		return ;
	}
	else if(pos==1)
	{
		temp=*h;
		*h=(*h)->next;
		free(temp);
	}

	else
	{
		node *curr=*h;
		i=1;
		while(i<pos-1&&curr->next)
		{
			curr=curr->next;
			i++;
		}
		if(curr->next==NULL)
		{
			printf("invalid input");
		}
		else
		{
			temp=curr->next;
			curr->next=curr->next->next;
			free(temp);
		}
	}
}
 void insert_pos(node** head, int pos)
 {
 	node* new=(node *)malloc(sizeof(node));
 	node *curr=*head;
 	int i;
 	i=1;
 	if(pos==1)
 	{
 		new->next=*head;
 		*head=new;
 		new->data=50;
	 }
	 else
	 {
	 
 	while(i<pos-1&&curr->next)
 	{
 		curr=curr->next;
 		i++;
	}
	if(i==pos-1)
	{
	new->next=curr->next;
	curr->next=new;
	new->data=50;
	}
	else
	printf("Invalid position\n");
}
 }

void insert_beg(node ** head, int data)
{
	node * new=(node *)malloc(sizeof(node));
	new->next=*head;
	*head=new;
	new->data=data;
	
}
void show_list(node * h)
{
	node * curr=h;
	printf("\n");
	while(curr)
	{
		printf("%d\t",curr->data);
		curr=curr->next;
	}
	
}

void main()
{
	int i;
	int pos;
	for(i=1;i<=10;i++)
	{
		insert_beg(&head,i);
	}
	
	show_list(head);
	printf("\n");
	
	reverse1(head);
	
	if(ispalindrome(head,head))
	printf("\nYES");
	else
	printf("\nNO");
	
	show_list(head);
}
