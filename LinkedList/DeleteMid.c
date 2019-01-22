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


void removeMid(struct Node *node)
{
	if(node == NULL)
	{
		return;
	}
	
	struct Node *ptr1 = node;
	struct Node *ptr2 = node;
	struct Node *prev = NULL;
	
	while(ptr2!= NULL && ptr2->next != NULL)
	{
		prev = ptr1;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	
	if(prev != NULL)
	{
	prev->next = ptr1->next;
	free(ptr1);
	}
	
	
}

/*struct Node* mid_recur(struct Node *ptr1, struct Node *ptr2)
{
	if(ptr2 == NULL)
		return NULL;
	if(ptr2->next == NULL)
		return ptr1;
	if(ptr2->next->next == NULL)
		return ptr1;
	
	return mid_recur(ptr1->next,ptr2->next->next);
}
  
struct Node *newNode(int key) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
}
 */
 
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
		insertEnd(i,&head);
	} 
	
    printList(head); 
    
    removeMid(head);
    
    printf("\n");
    printList(head);
    
    return 0; 
} 

