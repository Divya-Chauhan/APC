#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

void bubbleSort(int *arr, int n)
{
	int i, j;
	
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
	}
	
}

int main()
{
	int *arr;          //array of integers
	int size;          //size of array
	int i;
	
	scanf("%d",&size);
	arr = (int*) malloc (sizeof(int)*size);
	for(i = 0; i < size; i++)
	{
		scanf("%d",arr+i);
	}
	
	bubbleSort(arr, size);
	
	//Array after sort
	for(i = 0; i < size; i++)
	{
		printf("%d,  ",arr[i]);
	}
	
	return 0;
}
