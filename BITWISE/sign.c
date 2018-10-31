#include<stdio.h>
int sign(int num)
{
	return (num>>31)|(!(!num));         
}
void main()
{
	int num;
	scanf("%d",&num);
	printf("%d",sign(num))	;
} 
