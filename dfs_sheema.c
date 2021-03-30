#include<stdio.h>
int i,j,n, adjacent[100][100],visited[100];

int main()
{
    printf("Sheema Zainab MI 19MID0014\n");
    printf("Depth first Search algorithm\n");
    printf("Enter no of vertices: \n");
    scanf("%d",&n);
    printf("Enter the adjacent matrix values : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adjacent[i][j]);
        }
    }
 for(i=0;i<n;i++)
 {
     visited[i]=0;
 }
printf("enter the starting vertex : \n");
scanf("%d",&j);
dfs(j);
}

void dfs(int vertex)
{
    int i;
    visited[vertex]=1;
    printf("visited node %d\n",vertex);
    for(i=0;i<n;i++)
    {
        if (visited[i]==0&&adjacent[vertex][i]==1)
        {
            dfs(i);
        }
    }
}
