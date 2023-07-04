// source removal for topological sort

#include<stdio.h>

#include<stdlib.h>



int graph[10][10], n, visited[10]={0}, indegree[10]={0};



void creategraph()

{

	printf("no. of vertices :");

	scanf("%d",&n);

	printf("enter adjacency matrix: \n");

	for(int i=0; i<n; i++)

	{

		for(int j=0; j<n; j++)

		{

			scanf("%d",&graph[i][j]);

		}

	}

}



void main()

{

	int i, j, count=0;

	creategraph();



	for(i=0;i<n;i++)

	{

		for(j=0;j<n;j++)

		{

			indegree[i]+=graph[j][i];

		}

	}



	printf("indegree array\n");

	for(i=0; i<n; i++)

	{

		printf("%d\t",indegree[i]);

	}



	printf("\ntopologically sorted order:\n");

	while(count<n)

	{

		for(i=0;i<n;i++)

		{

			if(!visited[i] && !indegree[i] )

			{

				printf("%d\t",i);

				visited[i]=1;

				for(j=0;j<n;j++)

				{

					if(graph[i][j])

					{

						graph[i][j]=0;

						indegree[j]--;

					}

				}

				count++;

				break;

			}

		}

	}

}

