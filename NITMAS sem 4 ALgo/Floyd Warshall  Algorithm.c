#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*

5 9

1 2  3  0
3 2  4  0
1 3  8  0
1 5 -4  0
4 1  2  0
2 4  1  0
2 5  7  0
4 3 -5  0
5 4  6  0
*/

/*
4 7

1 2 3 0
2 1 8 0
2 3 2 0
3 4 1 0
4 1 2 0
1 4 7 0
3 1 5 0

*/

void display(int*,int);
int main()
{
	int*a,i ,j,v,e,w,k,*d,*s;
	a=(int*)calloc(10*10,sizeof(int));
	printf("\nEnter the number of vertices and edges in the graph:- ");
	scanf("%d %d",&v,&e);

	printf("\nEnter the edges:\n");
	while(e!=0)
	{
		scanf("%d %d %d %d",&i,&j,&w,&k);
		if(k==0)
			*(a+i*10+j)=w;
		else
			*(a+i*10+j)=*(a+j*10+i)=w;
		e--;
	}
	v++;
	d=(int*)malloc(v*v*sizeof(int));
	s=(int*)calloc(v*v,sizeof(int));
	for(k=0;k<v;k++)
	{
		for(i=1;i<v;i++)
		{
			for(j=1;j<v;j++)
			{
				if(k==0)
				{
					if(i==j)
						*(d+i*v+j)=0;
					else
						if(*(a+i*10+j)!=0)
						{						
							*(d+i*v+j)=*(a+i*10+j);
							*(s+i*v+j)=i;
						}
						else
							*(d+i*v+j)=INT_MAX;
				}
				else
				{
					if(*(d+i*v+k)==INT_MAX || *(d+k*v+j)==INT_MAX)
						continue;

					if(*(d+i*v+j) > (*(d+i*v+k)+*(d+k*v+j)))
					{
						*(d+i*v+j)=*(d+i*v+k)+*(d+k*v+j);
						*(s+i*v+j)=k;
					}
				}
			}
		}
	}
	printf("\nThe distance matrix:\n");
	display(d,v);
	printf("\nThe path matrix:\n");
	display(s,v);
	return 0;
}
void display(int*a,int v)
{
	int i,j;
	for(i=1;i<v;i++)
	{
		for(j=1;j<v;j++)
		{
			printf("%d\t",*(a+i*v+j));
		}
		printf("\n");
	}
}