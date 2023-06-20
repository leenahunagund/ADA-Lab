#include<stdio.h>
#include<stdlib.h>
#define n1 4
#define n2 1024
int count=0;

void merge(int *a, int *left, int *right, int l, int r)
{
	int i=0,j=0,k=0;

	
	while(i<l && j<r)
	{
		count++;
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}

	while(i<l)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	
	while(j<r)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}

int sort(int *a,int n)
{
	if(n<2)
	return count;
	
	int mid=n/2;
	int *left=(int*)malloc(mid*sizeof(int));
	int *right=(int*)malloc((n-mid)*sizeof(int));
	
	for(int i=0; i<mid; i++)
		left[i]=a[i];
	for(int i=mid; i<n; i++)
		right[i-mid]=a[i];

	sort(left,mid);
	sort(right,n-mid);
	merge(a,left,right,mid,n-mid);
	return count;
}

void worstcaseGenerator(int *a , int l , int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		int *left=(int*)malloc((m-l+1)*sizeof(int));
		int *right=(int*)malloc((r-m)*sizeof(int));
		for(int i=0;i<=m-l;i++)
			left[i]=a[i*2];
		for(int i=0;i<r-m;i++)
			right[i]=a[i*2+1];
		worstcaseGenerator(left,l,m);
		worstcaseGenerator(right,m+1,r);
		int i;
		for(i=0;i<=m-l;i++)
			a[i]=left[i];
		for(int j=0;j<r-m;j++)
			a[i+j]=right[j];
	}
}

int main()
{
	int n,i,cnt;
	FILE *f1,*f2,*f3;
	f1=fopen("bc.txt","a");
	f2=fopen("ac.txt","a");
	f3=fopen("wc.txt","a");

	for(n=n1;n<=n2; n*=2)
	{
		int *a=(int*)malloc(n*sizeof(int));

		//best case
		for(i=0;i<n;i++)
		{
			if(i==0)
			a[i]=rand()%100;
			else
			a[i]=a[i-1]+rand()%100;
		}
		count=0;
		cnt=sort(a,n);
		fprintf(f1,"%d\t%d\n",n,cnt);
		
		//worst case
		worstcaseGenerator(a,0,n-1);
		count=0;
		cnt=sort(a,n);
		fprintf(f3,"%d\t%d\n",n,cnt);

		//average case
		for(i=0;i<n;i++)
		{
			a[i]=rand()%100;
		}
		count=0;
		cnt=sort(a,n);
		fprintf(f2,"%d\t%d\n",n,cnt);
	}
	
	system("gnuplot>load 'command.txt'");
	fclose(f1);
	fclose(f2);
	fclose(f3);
}










































	
