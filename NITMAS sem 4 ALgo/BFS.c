#include<stdio.h>
#include<stdlib.h>
void BFS(int*, int*, int*, int);
void EnQueue(int*, int, int);
int DeQueue(int*);
int front = -1, rear = -1;
int main()
{
	int* a, n, i, j, val, * visited, c, *queue,flag;
	printf("\nEnter the number of vertices and edges:- ");
	scanf("%d %d", &n, &c);
	a = (int*)calloc(n * n, sizeof(int));
	visited = (int*)calloc(n, sizeof(int));
	queue = (int*)malloc(n * sizeof(int));

	printf("\nEnter the edges:\n");
	while (c != 0)
	{
		scanf("%d %d", &i, &j);
		*(a + i * n + j) = *(a + j * n + i) = 1;
		c--;
	}
	
	BFS(a, queue, visited, n);

	return 0;
}
void BFS(int* a, int* queue, int* visited, int n)
{
	int i, j, s;
	printf("\nEnter the source vertex:- ");
	scanf("%d",&s);
	printf("\nThe BFS Travsersal of the Graph:\n");
	EnQueue(queue, s, n);
	*(visited + s) = 1;

	while (front != -1)
	{
		printf("%d\t", *(queue + front));
		i = DeQueue(queue);
		*(visited + i) = 1;
		for (j = 0; j < n; j++)
		{
			if (*(a + i * n + j) == 1 && *(visited + j) == 0)
			{
				EnQueue(queue, j, n);
				*(visited + j) = 1;
			}
		}
	}
}
void EnQueue(int* a, int val, int n)
{
	if (rear < n - 1)
	{
		if (front == -1)
		{
			front++;
			rear++;
			*(a + rear) = val;
		}
		else
		{
			rear++;
			*(a + rear) = val;
		}
	}
}
int DeQueue(int* a)
{
	int val = *(a + front);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front++;

	return val;
}

