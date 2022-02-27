//0th element is the pivot

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void Display(int*, int);
void QuickSort(int*, int, int);
int Split(int*, int, int);
int main()
{
	int i,n,*a;
	printf("\nEnter the size of array:- ");
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	printf("\nEnter the elements:- ");
	for (i = 0; i < n; i++)
	{	
		scanf("%d", (a + i));
	}
	printf("\nOriginal Array:\n");
	Display(a, n);

	QuickSort(a, 0, n - 1);

	printf("\nSorted Array:\n");
	Display(a, n);

	return 0;
}
void Display(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", *(a + i));
	}
}
void QuickSort(int* a, int l, int r)
{
	int pos;

	if (r > l)
	{
		pos = Split(a, l, r);
		QuickSort(a, l, pos - 1);
		QuickSort(a, pos + 1, r);
	}
}
int Split(int* a, int l, int r)
{
	int p, q, num, temp;
	num = *(a + l);
	p = l + 1;
	q = r;

	while (q >= p)
	{
		while (*(a + p) < num)
			p++;
		while (*(a + q) > num)
			q--;
		
		if (q > p)
		{
			temp = *(a + p);
			*(a + p) = *(a + q);
			*(a + q) = temp;
		}
	}
	temp = *(a + l);
	*(a + l) = *(a + q);
	*(a + q) = temp;

	return q;
}