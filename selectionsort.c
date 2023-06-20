#include<stdio.h>
#include<stdlib.h>
#define n1 10
#define n2 100

int sort(int *a,int n){
int pos,temp,cnt=0,swap;
for(int i=0;i<n-1;i++){
pos =i;
for(int j=i+1;j<n;j++){
cnt++;
if(a[j]<a[pos]){
pos=j;
}}
temp=a[pos];
a[pos]=a[i];
a[i]=temp;
}
return cnt;}

void main(){
FILE *f1,*f2,*f3;
int x,y,z,n,*a;
f1=fopen("bc.txt","a");
f2=fopen("ac.txt","a");
f3=fopen("wc.txt","a");
for(n=n1;n<=n2;n=n+10){
a=(int*)malloc(n*sizeof(int));

//AVERAGE CASE
for(int i=0;i<n;i++)
a[i]=rand()%100;
x=sort(a,n);
fprintf(f2,"%d\t%d\n",n,x);

//BEST CASE
for(int i=0;i<n;i++){
if(i==0)
a[0]=rand()%100;
else
a[i]=a[i-1]+rand()%100;}
y=sort(a,n);
fprintf(f1,"%d\t%d\n",n,y);

//WORST CASE
for(int i=n-1;i>=0;i--){
if(i==n-1)
a[i]=rand()%100;
else
a[i]=a[i+1]+rand()%100;}
z=sort(a,n);
fprintf(f3,"%d\t%d\n",n,z);

}system("gnuplot>load 'commands.txt'");
fclose(f3);
fclose(f2);
fclose(f1);
}

