//dfs algorthim to check for connectivity amd acyclicity of a graph
#include<stdio.h>
#include<stdlib.h>
#define max 100

int graph[max][max],visited[max],iscyclic=0,dfscount=0,count=0;

void dfs(int n, int start , int parent)	
{
	visited[start]=1;
	printf("--->%c",start+65);
	for(int i=0;i<n;i++)	
	{
		if(i!=parent && graph[start][i] && visited[i])
		iscyclic=1;
		if(graph[start][i] && visited[i]==0){
		dfs(n,i,start);
		count++;
		}
	}
}

void main() 
{
	int start,n;
	printf("enter number of nodes in the graph : ");
	//n=rand()%100; 
	scanf("%d",&n);
	printf("the adjacency matrix \n");
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	//scanf("%d",&graph[i][j]);
	graph[i][j]=rand()%2;
	printf("%d\t",graph[i][j]);}
	visited[i]=0;
	printf("\n");
	}
printf("DFS traversal starting from node %c\n",start+65);
dfs(n,0,-1);
dfscount++;
if(count==n-1)
printf("graph is connected\n");
else
printf("graph is not connected\n");
start=1;
while(dfscount==n)
{
	if(visited[start]!=1){
	printf("\n");
	dfs(n,start,-1);
	dfscount++;
	}
start++;
}
printf("the number of components is %d\n", dfscount);
if(iscyclic)
printf("the graph is cyclic\n");
else	
printf("the graph is acyclic");
}



	

	
	
