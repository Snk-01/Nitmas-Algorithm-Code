#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>
void mergesort(int*, int, int);
void merge(int*, int, int, int);
void Display(int*, int);
int main()
{
	int* a, n, i;
	printf("\nEnter the size of array:- ");
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	printf("\nEnter the elements:- ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", (a + i));
	}
	printf("\nOriginal Array before sorting:\n");
	Display(a, n);
	mergesort(a, 0, n - 1);
	printf("\nArray after sorting:\n");
	Display(a, n);

	return 0;
}
void mergesort(int* a, int l, int r) // l=lowerbound left subarray  r=upperbound right subarray
{
	if (l < r)
	{
		int m;
		m = l + (r - l) / 2;

		mergesort(a, l, m);
		mergesort(a, m + 1, r);

		merge(a, l, m, r);
	}
}
void merge(int* a, int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m, * l1, * r1, i, j, k;
	l1 = (int*)malloc(n1 * sizeof(int));
	r1 = (int*)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		*(l1 + i) = *(a + l + i);

	for (j = 0; j < n2; j++)
		*(r1 + j) = *(a + m + 1 + j);

	i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (*(l1 + i) <= *(r1 + j))
		{
			*(a + k) = *(l1 + i);
			k++;
			i++;
		}
		else
		{
			*(a + k) = *(r1 + j);
			k++;
			j++;
		}
	}
	while (i < n1)
	{
		*(a + k) = *(l1 + i);
		k++;
		i++;
	}
	while (j < n2)
	{
		*(a + k) = *(r1 + j);
		k++;
		j++;
	}
}
void Display(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", *(a + i));
}

