/*
7 9
0 1 28
1 2 16
2 3 12
3 4 22
4 5 25
0 5 10
4 6 24
3 6 18
1 6 14
*/
/*
5 5
0 1 10
0 2 5
1 3 14
3 4 12
2 4 25
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void Min_SpanTree(int*,int);
int Find(int);
int Union(int,int);
int*parent;
int main()
{
	int* a, n, i, j, val, * selected, c, w;
	printf("\nEnter the number of vertices and number of edges:- ");
	scanf("%d %d", &n, &c);
	a = (int*)calloc(n * n, sizeof(int));
	parent = (int*)calloc(n,sizeof(int)); 
	printf("\nEnter the edges:\n");
	while (c != 0)
	{
		scanf("%d %d %d", &i, &j, &w);
		*(a + i * n + j) = *(a + j * n + i) = w;

		c--;
	}
	printf("\nThe minimum cost spanning tree is:\n");
	Min_SpanTree(a,n);
	return 0;
}
void Min_SpanTree(int*a,int n)
{
	int e1=0,i,j,min=INT_MAX,totalcost=0,s,e,u,v;
	while(e1<n-1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(*(a+i*n+j)!=0 && *(a+i*n+j)<min)
				{
					min=*(a+i*n+j);
					s=u=i;
					e=v=j;

				}
			}
		}
		u=Find(u);
		v=Find(v);
		if(Union(u,v))
		{
			printf("\n%d-%d %d \n",s,e,min);
			totalcost+=min;
			e1++;
		}
		*(a+s*n+e)=*(a+e*n+s)=INT_MAX;
		min=INT_MAX;
		
	}
	printf("\nTotal minimum cost of the spanning tree is: %d",totalcost);
}
int Find(int u)
{
	while(parent[u])
	{
		u=parent[u];
	}
	return u;
}
int Union(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	else
		return 0;
}