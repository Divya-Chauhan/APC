#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int i, int j)
{
	int x = a[i];
	a[i] = a[j];
	a[j] = x;
}

void quickSort(int *a, int left, int right)
{

	if(left >= right)  return ;
	
	int pivot = left, i;
	int x = left;
	
	for(i = left + 1; i <= right; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(a, ++x, i);
		}
	}
	
	swap(a, pivot, x);
	quickSort(a, left, x - 1);
	quickSort(a, x + 1, right);

}

int main()
{
	
	int n, i;
	scanf("%d",&n);
	int *arr = (int *) malloc (sizeof(int)*n);
	
	//int n=sizeof(arr)/sizeof(arr[0]);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d",arr+i);
	}

	quickSort(arr, 0, n-1);
	
	for(i = 0; i < n; i++)
	{
		printf("%d   ",arr[i]);
	}
	return 0;

}
