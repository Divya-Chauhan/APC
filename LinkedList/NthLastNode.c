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


void nthLastNode(struct Node *node, int n)
{
	static int x = 0;
	
	if(node == NULL)
	return;
	
	nthLastNode(node->next, n);
	x++;
	
	if(x == n)
	{
		printf("%dth Node from End : %d",n,node->data);
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
    int n;
    
	for(i = 0; i < 10; i++)
	{
		insertEnd(i,&head);
	} 
	
    printList(head); 
    
    scanf("%d",&n);
    nthLastNode(head,n);
    
    return 0; 
} 


