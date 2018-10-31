#include <stdio.h>

void main()
{
	int num, n;
	int result;
	
	scanf("%d %d", &num, &n);
	
	result = ((num >> (n << 3)) & (0xFF));
	// n << 3 -> Multiply by 8
	// x >> (n << 3) -> Right Shift by 0, 8, 16 and 24 bytes
	
	printf("%d", result);
}
