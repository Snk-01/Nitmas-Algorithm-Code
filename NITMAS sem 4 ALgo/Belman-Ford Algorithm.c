#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
6 6

0 1 6
1 2 3
3 1 9
2 3 4
3 4 3
2 5 5
*/

/*
7 10

0 1 6
0 2 5
0 3 5
1 4 -1
2 4 1
2 1 -2
3 2 -2
3 5 -1
5 6 3
4 6 3

*/

struct edge
{
	int s,e,w;
};
int main()
{
	int v,ed,*dp,i,u1,v1,w1,j;
	struct edge*edges;
	printf("\nEnter the number of vertices and edges:-  ");
	scanf("%d %d",&v,&ed);

	edges=(struct edge*)calloc(ed,sizeof(struct edge));
	dp=(int*)malloc(v*sizeof(int));


	for(i=0;i<ed;i++)
	{
		printf("\nEnter start, end and weight of edge %d : ",(i+1));
		scanf("%d %d %d",&(edges+i)->s,&(edges+i)->e,&(edges+i)->w);
	}
	for(i=0;i<ed;i++)
	{
		
		printf("%d %d %d",(edges+i)->s,(edges+i)->e,(edges+i)->w);
		printf("\n");
	}

	for(i=0;i<v;i++)
	{
		*(dp+i)=INT_MAX;
	}
	*(dp+0)=0;
	for(i=1;i<v;i++)
	{
		for(j=0;j<ed;j++)
		{
			u1=edges[j].s;
			v1=edges[j].e;
			w1=edges[j].w;

			if(dp[u1]!=INT_MAX && dp[u1]+w1<dp[v1])
				dp[v1]=dp[u1]+w1;
		}
	}
	for(i=0;i<v;i++)
		printf("%d\t",dp[i]);

	return 0;
}