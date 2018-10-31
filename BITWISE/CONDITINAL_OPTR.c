#include<stdio.h>
void main()
{
	int a, b, c, x;
	scanf("%d %d %d", &a, &b, &c);     
	     
	int result= (!a * b) ^ (!(!a) * c) ^ b ^ c;     //if number is true i.e , !true = false !num=0
	// 0*b =0
	// !0 = 1 ...... 1*b= b
	// b^b =0 so       b^b^c=c;    when num = x as !0=1 ... 1*b=b ....!1*c=0)..... b^0^b^c
	// similarly we get 0^c^b^c=b;
	
	printf("%d\n",result); 
	
	//or 
    x = (a >> 31) | ((~a + 1) >> 31);    // if a != 0 i.e., true then x will become -1 i.e., all ones in binary ;
	result = ((x & b) + (~x & c));
	
	printf("%d",result);
}
