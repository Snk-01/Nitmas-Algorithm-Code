#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void Min_SpanTree(int*, int*, int);
int main()
{
	int* a, n, i, j, val, * selected, c, w;
	printf("\nEnter the number of vertices and number of edges:- ");
	scanf("%d %d", &n, &c);
	a = (int*)calloc(n * n, sizeof(int));
	selected = (int*)calloc(n , sizeof(int)); 
	printf("\nEnter the edges:\n");
	while (c != 0)
	{
		scanf("%d %d %d", &i, &j, &w);
		*(a + i * n + j) = *(a + j * n + i) = w;
		c--;
	}
	printf("\nThe minimum spanning tree is:\n");
	Min_SpanTree(a, selected, n);

	return 0;
}
void Min_SpanTree(int* a, int* selected, int n)
{
	int i, j, e1 = 0, s, e, min, total = 0;
	*(selected + 0) = 1;
	while (e1 < n - 1)
	{
		s = -1, e = -1;
		min = INT_MAX;

		for (i = 0; i < n; i++)
		{
			if (selected[i])
			{
				for (j = 0; j < n; j++)
				{
					if (selected[j] == 0 && *(a + i * n + j) != 0)
					{
						if (min > *(a + i * n + j))
						{
							s = i;
							e = j;
							min = *(a + i * n + j);
						}
					}
				}
			}
		}
		printf("\n%d-%d=%d", s, e, min);
		*(selected + e) = 1;
		e1++;
		total += min;
	}
	printf("\nTotal Minimum cost= %d", total);

}