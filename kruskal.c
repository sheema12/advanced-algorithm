#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,a,b,u,v,n,ind=1;
int min,mincost=0,weight[20][20],parent[10];
int find(int);
int compare(int,int);
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int compare(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int  main()
{

	printf("\nSheema zainab MI 19MID0014\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the weight between vertices :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&weight[i][j]);
			if(weight[i][j]==0)
				weight[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ind < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(weight[i][j] < min)
				{
					min=weight[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(compare(u,v))
		{
			printf("%d edge ==(%d,%d) weight==%d\n",ind++,a,b,min);
			mincost +=min;
		}
		weight[a][b]=weight[b][a]=999;
	}
	printf("\n\tMinimum cost of the graph = %d\n",mincost);

}
