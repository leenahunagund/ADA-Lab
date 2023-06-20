//euclid algo 
#include<stdio.h>
#include<stdlib.h>

/*int gcd(int x, int y)
{
	int r;
	while(y!=0)
	{
		r=x%y;
		x=y;
		y=r;
	}
return x;
} */


int gcd(int x, int y)
{
	int r;
	if(y==0)
	return x;
 	else
	{
		r=x%y;
		gcd(y,r);
	}
}
	
	
void main()
{
	int a,b,r;
	printf("enter the 2 numbers to find gcd :");
	scanf("%d%d", &a,&b);
	r=gcd(a,b);
	printf("the gcd of the 2 numbers are: %d", r);
}

		
		
