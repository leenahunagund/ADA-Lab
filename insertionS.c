//insertion sort
#include<stdio.h>
#include<stdlib.h>
#define n1 10
#define n2 100

int sort(int *a,int n){
int key,c=0,j;
for(int i=0;i<n;i++){
key=a[i];
for( j=i-1;j>=0 && a[j]>key ;j--){
a[j+1]=a[j];
c++;
}
a[j+1]=key;
}
return c;
}

void main()
{
FILE *f1,*f2,*f3;
int c,n;
f1=fopen("bc.txt","a");
f2=fopen("ac.txt","a");
f3=fopen("wc.txt","a");
for(n=n1;n<=n2;n=n+10)
{
int *a=(int*)malloc(n*sizeof(int));

//best case 
for(int i=0;i<n;i++){
if(i==0)
a[i]=rand()%100;
else
a[i]=a[i-1]+rand()%100;
}
c=sort(a,n);
fprintf(f1,"%d\t%d\n",n,c);

//avg case 
for(int i=0;i<n;i++){
a[i]=rand()%100;
}
c=sort(a,n);
fprintf(f2,"%d\t%d\n",n,c);

//worst case 
for(int i=n-1;i>=0;i--){
if(i==n-1)
a[i]=rand()%100;
else
a[i]=a[i+1]+rand()%100;
}
c=sort(a,n);
fprintf(f3,"%d\t%d\n",n,c);
}

system("gnuplot>load 'commands.txt'");
fclose(f3);
fclose(f2);
fclose(f1);
}
