//dfs algorthim to check for connectivity amd acyclicity of a graph
#include<stdio.h>
#include<stdlib.h>
#define max 100

int cyclic=0,bfscount=0,count=0,ordercount=0;

void bfs(int graph[][max], int visited[], int n, int start )	
{
	int queue[max],parent[max];	
	 int rear=-1,front=-1,parentnode,i;
	visited[start]=1;
	queue[++rear]=start;
	parent[rear]=-1;
	while(rear!=front)
	{
		start=queue[++front];
		parentnode=parent[front];
		printf("--->%c",start+65);
		for(i=0;i<n;i++){
		ordercount++;
		if(i!=parentnode && graph[start][i] && visited[i])
		cyclic=1;
		if(graph[start][i] && visited[i]==0){
		queue[++rear]=i;
		parent[rear]=start;
		visited[i]=1;
		count++;}}}
}

void main() 
{
	int graph[max][max],visited[max],i,j,start,n;
	printf("enter number of nodes in the graph : ");
	//n=rand()%100; 
	scanf("%d",&n);
	printf("the adjacency matrix \n");
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
//	scanf("%d",&graph[i][j]);}
	graph[i][j]=rand()%2;
	printf("%d\t",graph[i][j]);}
	visited[i]=0;
	printf("\n");
	}
printf("BFS traversal\n");
bfscount++;
bfs(graph,visited,n,0);
if(count==n-1)
printf("graph is connected\n");
else {
printf("graph is not connected\n");
start=1;
while(count==n)
{
	if(visited[start]!=1){
	bfscount++;
	bfs(graph,visited,n,start);
	}
start++;
} }
printf("the number of components is %d\n", bfscount);
if(cyclic)
printf("the graph is cyclic\n");
else	
printf("the graph is acyclic");
}



	

	
	
