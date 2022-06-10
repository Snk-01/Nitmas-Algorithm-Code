#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
9
17
0 1
0 4
0 5
0 3
1 5
1 6
1 7
2 5
2 6
3 7
4 5
4 8
5 6
5 8
6 7
6 8
7 8
*/
void Graph_color(int*,int);
int main()
{
	int* a, n, i, j,c;
	printf("\nEnter the number of vertices and number of edges:- ");
	scanf("%d %d", &n, &c);
	a = (int*)calloc(n * n, sizeof(int)); 
	printf("\nEnter the edges:\n");
	while (c != 0)
	{
		scanf("%d %d", &i, &j);
		*(a + i * n + j) = *(a + j * n + i) = 1;

		c--;
	}
	Graph_color(a,n);
	return 0;
}
void Graph_color(int*a,int n)
{
	int *colors,*vertices,*color2,i,j,val,k;
	vertices=(int*)malloc(n*sizeof(int));
	color2=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		*(vertices+i)=-1;
	}
	*(vertices+0)=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(a+i*n+j)==1 && *(vertices+j)!=-1)
			{
				*(color2+*(vertices+j))=1;
			}
		}
		val=-1;
		for(j=0;j<n;j++)
		{
			if(*(color2+j)==0)
			{
				val=j;
				break;
			}
		}
		*(vertices+i)=val;
		for(j=0;j<n;j++)
		{
			if(*(a+i*n+j)==1 && *(vertices+j)!=-1)
			{
				*(color2+*(vertices+j))=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n%d %c\n",i,(char)(*(vertices+i)+65));
	}
}