#include <stdio.h>

int bitAnd(int num1, int num2)
{
	return ~((~num1) | (~num2));
}

int main()
{
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	printf("num1 & num2 :%d\n", bitAnd(num1, num2));
	
	return 0;
}
