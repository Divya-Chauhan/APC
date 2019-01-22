/*
** Delete duplicates form sorted linked list
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

void deleteDuplicate(struct Node *head)
{
	if(head == NULL)
		return;
	
	struct Node *curr = head;
	struct Node *temp = NULL;
	
	while(curr->next != NULL)
	{
		if(curr->data == curr->next->data )
		{
			temp = curr->next;
			curr->next = temp->next;
			free(temp);
		}
		else
		{
			curr = curr->next;
		}
	}
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
    int i;
    struct Node *curr;
    int n;
    
	for(i = 0; i < 11; i++)
	{
		if(i == 0 || i == 10)
		{
			insertEnd(i,&head);
			insertEnd(i,&head);
		}
		
		insertEnd(i,&head);
		
	} 
	
    printList(head); 
    
    deleteDuplicate(head);
    
    printf("\n");
    printList(head);
    
    return 0; 
} 

