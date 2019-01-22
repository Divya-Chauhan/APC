/*
** Reverse a Linked List in groups of given size.
** example 
** list : 1 2 2 4 5 6 7 8
** n : 4
** result : 4 2 2 1 8 7 6 5
*/


#include<stdio.h> 
#include<stdlib.h> 

struct Node {
	int data;
	struct Node *next;
};

void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d  ",node->data); 
        node = node->next; 
    } 
} 


struct Node* reverse(struct Node *head,struct Node *end)
{
	struct Node *curr = head;
	struct Node *next;
	struct Node *prev = end;
	
	while(curr != end)
	{
		//printf("eneter loop 2\n");
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}

void reverseN(struct Node **head, int n)
{
	int count = 0;
	struct Node *curr = *head;
	struct Node *start = *head;
	struct Node *temp;
	while(curr != NULL)
	{
		//printf("entered loop1 \n");
		count++;
		if(count == n)
		{
			temp = *head;
			*head = reverse(*head,curr->next);
			start = temp;
		}
		else if(count%n == 0)
		{
			//printf("\n%d %d",start->next->data,curr->data);
			temp = start->next;
			start->next = reverse(start->next,curr->next);
			//printf("\n%d",start->next->data);
			start = temp;
		}
		curr = curr->next;
	}
	
	//start->next = reverse(start->next,curr);

	
}

void insertEnd(int data, struct Node **head)
{
	struct Node *temp=(struct Node *) malloc (sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	struct Node *curr = *head;
	
	if(*head == NULL)
		*head = temp;
	else
	{
		while(curr->next)
			curr=curr->next;
		curr->next=temp;
	}
} 

int main() 
{ 
    struct Node *head = NULL; 
    int n;
    int i;
    
	for(i = 0; i < 11; i++)
	{
		insertEnd(i,&head);
	} 
	
    printList(head); 
    
    scanf("%d",&n);
    reverseN(&head,n);
    
    printf("\n");
    
    printList(head); 
   
    return 0; 
} 

