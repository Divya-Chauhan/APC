#include<stdio.h> 
#include<stdlib.h> 

struct Node {
	int data;
	struct Node *next;
};


void removeLoop(struct Node *ptr1, struct Node *ptr2)
{
	while(ptr1->next != ptr2->next)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
//	ptr1 = ptr1->next;
	printf("LOOP AT %d\n",ptr1->next->data);
	ptr2->next = NULL;
	return;
}


void detectLoop(struct Node *head)
{
	struct Node *curr1 = head;
	struct Node *curr2 = head;
	while(curr2->next && curr2->next->next)
	{
		curr1 = curr1->next;
		curr2 = curr2->next->next;
		
		if(curr1 == curr2)
			break;
	}
	
	if(curr1 == curr2)
	{
		printf("LOOP DETECTED\n");
		removeLoop(head,curr2);	
	}
	return;
	
}

void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d  ",node->data); 
        node = node->next; 
    } 
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

    
	for(i = 0; i < 10; i++)
	{
		insertEnd(i,&head);
	} 
	
	curr = head;
  
    /* Create a loop for testing */
    while(curr->next != NULL)
    {
    	curr = curr->next;
	}
	
	curr->next = head->next->next;
  
    detectLoop(head); 
  
    printf("Linked List after removing loop \n"); 
    printList(head); 
    return 0; 
} 


