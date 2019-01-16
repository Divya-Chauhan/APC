#include<stdio.h>

void split(int arr[], int left, int right)
{
	if(right <= left)
	return ;
	
	int mid = (left+right)/2;

	
	split(arr, left, mid);
	split(arr,mid+1,right);
	//printf("%d  %d   %d\n",left,mid,right);

	merge(arr,left, mid, right);
	
	
}

int merge(int arr[], int left, int mid, int right)
{
	int i, j;
	int *aux = malloc (sizeof(int) *(right-left+1));
	i = left;
	j = mid + 1;
	int k;
	for(k = 0; k < right - left + 1; k++)
	{
		if(i > mid)
		{
			aux[k] = arr[j];
			j++;
		}
		else if( j > right)
		{
			aux[k] = arr[i];
			i++;
		}
		else if(arr[i] <= arr[j])
		{
			aux[k] = arr[i];
			i++;
		}
		else
		{
			aux[k] = arr[j];
			j++;
		}
	}
	j=0;
	for(i = left ; i <= right ; i++)
	{
		//printf("%d  ",aux[j]);
		arr[i] = aux[j];
		j++;
	}
	printf("\n");
	
}

int main()
{
	int arr[] = {1,6,3,2,7,0};
	int i;
	int size = sizeof(arr)/sizeof(arr[0]);
	split(arr,0,size-1);
	for(i = 0; i<size; i++)
	{
		printf("%d\n",arr[i]);
	}
}
