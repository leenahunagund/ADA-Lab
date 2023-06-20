#include<stdio.h>
#include<stdlib.h>
#define p 10
#define q 100
#define r 10
int count=0;
int BS(int *a,int n,int ele){
int b=0,e=n-1;
int m;
while(b<=e){
  count++;
m=(b+e)/2;
if(a[m]==ele)
break;
else if(a[m]>ele)
e=m-1;
else
b=m+1;
}
return m+1;
}

void main(){
FILE *fp1,*fp2,*fp3;
int ele,i,*a,j,x,y,z;
fp1=fopen("bc.txt","a");
fp2=fopen("wc.txt","a");
fp3=fopen("ac.txt","a");
for(i=p;i<=q;i=i+r){
a=(int*)malloc(i*sizeof(int));
a[0]=rand()%100;
for(j=1;j<i;j++)
a[j]=a[j-1]+rand()%100;
//BEST CASE
ele=a[0];
x=BS(a,i,ele);
fprintf(fp1,"%d\t%d\n",i,x);
//WORST CASE
ele=a[i];
y=BS(a,i,ele);
fprintf(fp2,"%d\t%d\n",i,y);
//AVERAGE CASE
ele=a[(i-1)/2+(i-1)/4];
z=BS(a,i,ele);
fprintf(fp3,"%d\t%d\n",i,z); 
}system("gnuplot>load 'command.txt'");
fclose(fp1);
fclose(fp2);
fclose(fp3);
}  
