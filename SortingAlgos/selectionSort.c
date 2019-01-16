#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n)
{
	int i, j;
	int index;                //index of minimum element
	int temp;                 //temporary variable for swaping
	
	for(i = 0; i < n-1; i++)
	{
		index = i;
		for(j = i+1; j < n; j++)
		{
			index = arr[j] < arr[index]? j : index;
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
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
	
	selectionSort(arr, size);
	
	//Array after sort
	for(i = 0; i < size; i++)
	{
		printf("%d",arr[i]);
	}
	
	return 0;
}
