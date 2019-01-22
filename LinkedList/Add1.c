/*
**Add 1 to a number represented as linked list
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

struct Node *newNode(int key) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
    
}

int addOne(struct Node **head, struct Node *curr)
{
	int rem = 0;
	
	if(curr == NULL)
	{
		return 1;
	}
	
	if(addOne(head,curr->next))
	{
		rem = (curr->data + 1)/10;
		curr->data = (curr->data+1)%10;
	}
	
	if(curr == *head && rem)
	{
		struct Node *temp = *head;
		*head = newNode(1);
		(*head)->next = temp;
		rem = 0;
	}
	
	return rem;
	
}

int main() 
{ 
    struct Node *head = NULL; 
    
    head = newNode(5);
	head->next = newNode(9);
	head->next->next = newNode(9);
	
    printList(head); 
    addOne(&head,head);
    printf("\n");
    printList(head);
    
    return 0; 
} 

