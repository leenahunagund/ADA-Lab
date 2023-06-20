//linear search
#include <stdio.h>
#include<stdlib.h>
#define n1 10
#define n2 100

int search(int *a , int n, int key )
{
 int c=0;
  for (int i = 0; i < n; i++)
  {
	c++;
    if (key==a[i])  
    {
   //   printf("%d is present at location %d\n", search, i+1);
      return c;
    }
  }

    printf("%d isn't present in the array\n", key);
return c;

}

void main()
{
  int *a, key,i, n,count;
 FILE *f1,*f2,*f3;

for(n=n1;n<=n2;n+=10)
{
f1=fopen("bc.txt","a");
f2=fopen("ac.txt","a");
f3=fopen("wc.txt","a");
a=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
a[i]=rand()%100;

//best case
key=a[0];
count=search(a,n,key);
fprintf(f1,"%d\t%d\n",n,count);

//avg case 
key=a[n/2];
count=search(a,n,key);
fprintf(f2,"%d\t%d\n",n,count);

//worst case
key=999;
count=search(a,n,key);
fprintf(f1,"%d\t%d\n",n,count);
}

system("gnuplot>load 'command.txt'");
fclose(f3);
fclose(f2);
fclose(f1);
}



 



	
