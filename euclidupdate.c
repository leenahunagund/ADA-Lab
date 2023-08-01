#include<stdio.h>
#include<stdlib.h>
int cnt=0;
void euclid(int m,int n){
int r;
while(n!=0){
cnt++;
r=m%n;
m=n;
n=r;
}
}
void repsub(int m,int n){
while(m>=n){
cnt++;
m=m-n;
}
}
void cic(int m,int n){
int s=n;
while(s>0){
cnt++;
if(m%s==0 && n%s==0){
break;
}
s--;
}
}
void main(){
FILE *f1;
f1=fopen("gcd.txt","a");
int m,n,y,z,x=1;
while(x<=10){
n=rand()%100;
y=n;
z=n+rand()%100;
//bestcaseforeuclid
cnt=0;
m=y;
euclid(m,n);
int eb1=cnt;
//worstcaseforeuclid
cnt=0;
m=z;
euclid(m,n);
int ew1=cnt;
//bestcaseforrepsub
cnt=0;
m=y;
repsub(m,n);
int rsb1=cnt;
//worstcaseforrepsub
cnt=0;
m=z;
repsub(m,1);
int rsw1=cnt;
//bestcaseforcic
cnt=0;
m=n;
cic(y,n);
int cicb1=cnt;
//worstcaseforcic
cnt=0;
m=z;
cic(m,n);
int cicw1=cnt;
fprintf(f1,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",x,n,y,z,eb1,ew1,rsb1,rsw1,cicb1,cicw1);
x++;
}
fclose(f1);
}
