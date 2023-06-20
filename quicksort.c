#include<stdio.h>
#include<stdlib.h>
#define n1 10
#define n2 100
int count=0;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition( int *a,int low,int high)
{
	int pivot=a[high];
	int i=(low-1);
	for(int j=low;j<=high;j++)
	{
		count++;
		if(a[j]<pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return(i+1);
}

int sort( int *a,int low,int high)
{
		if(low<high)
		{
			int pi=partition(a,low,high);
			sort(a,low,pi-1);
			sort(a,pi+1,high);
		}
		return count;
}



void main()
{
	int cnt,*a,n;
	FILE *f1,*f2,*f3;
	f1=fopen("bc.txt", "a");
	f2=fopen("ac.txt", "a");
	f3=fopen("wc.txt", "a");
	
	for(n=n1;n<=n2;n+=10)
	{
		a=(int*)malloc(n*sizeof(int));

		//best case
		for(int i=0;i<n;i++)	
			a[i]=rand()%100;
		count=0;
		cnt=sort(a,0,n-1);
		fprintf(f1,"%d\t%d\n",n,cnt);
		
		//average case
		for(int i=0;i<n;i++)
			a[i]=rand()%100;
		count=0;
		cnt=sort(a,0,n-1);
		fprintf(f2,"%d\t%d\n",n,cnt);
	
		//worst case 
		for(int i=n-1;i>=0;i--)
		{	
			if(i==n-1)
				a[i]=rand()%100;
			else
				a[i]=a[i+1]+rand()%100;
		}
		count=0;
		cnt=sort(a,0,n-1);
		fprintf(f3,"%d\t%d\n",n,cnt);
	}
system("gnuplot>load 'commands.txt'");
fclose(f1);
fclose(f2);
fclose(f3);
}
		
		
		
			
		
				
		
