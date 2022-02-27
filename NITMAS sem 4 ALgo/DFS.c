#include<stdio.h>
#include<stdlib.h>
void Push(int*, int, int);
int Pop(int*);
void DFS(int*, int*, int*, int);
int top = -1;
int main()
{
	int* a, n, i, j, val, * stack, * visited, c,flag;
	printf("\nEnter the number of vertices and edges:- ");
	scanf("%d %d", &n, &c);
	a = (int*)calloc(n * n, sizeof(int));
	stack = (int*)malloc(n * sizeof(int));
	visited = (int*)calloc(n, sizeof(int));

	printf("\nEnter the edges:\n");
	while (c--!= 0)
	{
		scanf("%d %d", &i, &j);
		*(a + i * n + j) = *(a + j * n + i) = 1;
	}
	DFS(a, stack, visited, n);
	return 0;
}
void DFS(int* a, int* stack, int* visited, int n)
{
	int i, j, s;
	printf("\nEnter the source vertex:- ");
	scanf("%d",&s);
	printf("\nThe DFS traversal of the graph:\n");
	Push(stack, s, n);
	*(visited + s) = 1;
	while (top != -1)
	{
		printf("%d\t", *(stack + top));
		i = Pop(stack);
		for (j = 0; j < n; j++)
		{
			if (*(a + i * n + j) == 1 && *(visited+j)==0)
			{
				Push(stack, j, n);
				*(visited + j) = 1;
			}
		}
	}
}
void Push(int*a,int val,int n)
{
	if (top < n - 1)
	{
		top++;
		*(a + top) = val;
	}
}
int Pop(int*a)
{
	return *(a + top--);
}
