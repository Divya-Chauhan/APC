#include <stdio.h>

void main()
{
	int num, n;
	int result;
	
	scanf("%d %d", &num, &n);
	
	//result  = (num >> n) & ( ~((1 << 31) >> n << 1)) ); 
	result = ~(((1 << 31) >> n) << 1);
	result = result & (num >> n);
	
	printf("%d", result);
		
}
