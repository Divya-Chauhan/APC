#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int n)
{
	int i, j;
	int key;
	for(i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		while(j >= 0 && key < arr[j])
		{
			arr[j+1] = arr[j]; 
			j = j-1; 
		}
		arr[j+1] = key;
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
	
	insertionSort(arr, size);
	
	//Array after sort
	for(i = 0; i < size; i++)
	{
		printf("%d",arr[i]);
	}
	
	return 0;
}
