#include<stdio.h>

#include<stdlib.h>

#include<time.h>



int count=0;

void heapify(int a[],int n,int i){

count++;

int largest=i;

int left=2*i*1;

int right=2*i+1;

if (left<n && a[left]>a[largest])

	largest=left;

if(right<n && a[right]>a[largest])

	largest=right;

if(largest!=i){

	int temp=a[i];

	a[i]=a[largest];

	a[largest]=temp;

	heapify(a,n,largest);}}



void sort(int a[],int n){

	for( int i=n/2 -1;i>=0;i--)

	heapify(a,n,i);

	for(int i = n-1;i>=0;i--){

		int temp=a[0];

		a[0]=a[i];

		a[i]=temp;

		heapify(a,i,0);}}



void main(){

FILE *f1,*f2,*f3;

int x,y,z,n,*a;

srand(0);

f1=fopen("bc.txt","a");

f2=fopen("ac.txt","a");

f3=fopen("wc.txt","a");

for(n=10;n<=100;n=n+10){

a=(int*)malloc(n*sizeof(int));

//AVERAGE CASE

for(int i=0;i<n;i++)

a[i]=rand()%100;

count = 0;

sort(a,n);

fprintf(f2,"%d\t%d\n",n,count);



//BEST CASE

for(int i=0;i<n;i++){

if(i==0)

a[0]=rand()%100;

else

a[i]=a[i-1]+rand()%100;}

count = 0;

sort(a,n);

fprintf(f1,"%d\t%d\n",n,count);



//WORST CASE

for(int i=n-1;i>=0;i--){

if(i==n-1)

a[i]=rand()%100;

else

a[i]=a[i+1]+rand()%100;}

count=0;

sort(a,n);

fprintf(f3,"%d\t%d\n",n,count);



}system("gnuplot>load 'commands.txt'");

fclose(f3);

fclose(f2);

fclose(f1);

}





