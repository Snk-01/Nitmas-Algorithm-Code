#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
9 14

0 1 4
0 7 8
1 2 8
7 8 7
7 6 1
2 5 4
2 8 2
6 8 6
6 5 2
2 3 7
5 3 14
5 4 10
3 4 9
1 7 11

*/


void Dijkstra(int*,int);
int main()
{
	int*a,i ,j,v,e,w,k,*d,*s;
	a=(int*)calloc(10*10,sizeof(int));
	printf("\nEnter the number of vertices and edges in the graph:- ");
	scanf("%d %d",&v,&e);
	printf("\nEnter the edges:\n");
	while(e!=0)
	{
		scanf("%d %d %d",&i,&j,&w);
		*(a+i*10+j)=*(a+j*10+i)=w;
		e--;
	}
	Dijkstra(a,v);
	return 0;
}
void Dijkstra(int*a,int v)
{
	int*distance,*selected,i,j,s,k,min,min_index;
	distance=(int*)malloc(v*sizeof(int));
	selected=(int*)calloc(v,sizeof(int));

	for(i=0;i<v;i++)
		*(distance+i)=INT_MAX;

	*(distance+0)=0;

	for(k=1;k<=v-1;k++)
	{
		min=INT_MAX;
		min_index=-1;
		for(i=0;i<v;i++)
		{
			if(*(selected+i)==0 && *(distance+i)<=min)
			{
				min=*(distance+i);
				min_index=i;
			}
		}
		*(selected+min_index)=1;
		for(i=0;i<v;i++)
		{
			if(*(selected+i)==0 && *(a+min_index*10+i)>0 && *(distance+min_index)!=INT_MAX && *(distance+min_index)+*(a+min_index*10+i) < *(distance+i))
			{
				*(distance+i)=*(distance+min_index)+*(a+min_index*10+i);

			}
		}
	}
	for(i=0;i<v;i++)
		printf("%d\t",*(distance+i));
}