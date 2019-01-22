/*
**  Assuming that mid = (N-1)/2 for even sized array
**  and mid = N/2 for odd size linked list
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


struct Node* mid(struct Node *node)
{
	if(node == NULL)
	{
		return NULL;
	}
	
	struct Node *ptr1 = node;
	struct Node *ptr2 = node;
	
	while(ptr2->next != NULL && ptr2->next->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	return ptr1;
}

struct Node* mid_recur(struct Node *ptr1, struct Node *ptr2)
{
	if(ptr2 == NULL)
		return NULL;
	if(ptr2->next == NULL)
		return ptr1;
	if(ptr2->next->next == NULL)
		return ptr1;
	
	mid_recur(ptr1->next,ptr2->next->next);
}
  
/*struct Node *newNode(int key) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} */
 
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
    
    //scanf("%d",&n);
    struct Node *midnode = mid_recur(head,head);
    
    printf("\n%d",midnode->data);
    
    return 0; 
} 

