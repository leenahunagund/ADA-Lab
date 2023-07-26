#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return (a>b) ? a : b;
}

void main(){
	int t[100][100], v[100], w[100], n, m, i, j;
	printf("No. of Items>> ");
	scanf("%d",&n);
	printf("Sack Capacity>> ");
	scanf("%d",&m);
	
	
	printf("Weights:\n");
	for(i=1;i<n+1;i++){
		scanf("%d",&w[i]);
	}
    printf("values:\n");
    for(i=1;i<n+1;i++)
    {
        scanf("%d",&v[i]);
    }
	
	for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++){
			if (i==0||j==0)
				t[i][j] = 0;
			else if (j<w[i])
				t[i][j] = t[i-1][j];
			else
				t[i][j] = max(t[i-1][j], v[i]+t[i-1][j-w[i]]);
		}
	}
	
	printf("Maximum Value: %d\n",t[n][m]);
	
	printf("table:\n");
	for(i=0;i<n+1;i++)
    {
        for(j=0;j<m+1;j++)
        {
        printf("%d\t",t[i][j]);
        }
        printf("\n");
    }
}
