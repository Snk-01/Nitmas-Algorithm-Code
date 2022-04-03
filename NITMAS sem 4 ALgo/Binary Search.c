#include<stdio.h>
#include<stdlib.h>
void display(int*, int);
void bubble(int*, int);
int search(int*, int, int,int);
int main()
{
	int i,b,p,*a,n;
	printf("\nEnter the size of array:- ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements:- ");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));

	printf("\nThe given array is:-\n");
	display(a,n);
	printf("\nEnter the element to be searched:-");
	scanf("%d", &p);

	b=search(a, p, 0, n-1);

	if (b == 1)
		printf("\nElement found.\n");
	else
		printf("\nElement not found.\n");

	return 0;

}
void display(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", *(a + i));
}
int search(int* a, int val,int lb,int ub)
{
	int mid;
	if (lb > ub)
		return 0;

	mid = (lb + ub) / 2;

	if (*(a + mid) > val)
	{
		ub = mid - 1;
		search(a, val, lb, ub);
	}
	else
		if (*(a + mid) < val)
		{
			lb = mid + 1;
			search(a, val, lb, ub);
		}
		else
		{
			return 1;
		}
}
