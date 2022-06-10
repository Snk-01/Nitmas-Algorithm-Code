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
int CycleFound(int*,int*,int,int);
void Hamiltonian(int*,int);
int isValid(int*,int*,int,int,int);
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
	Hamiltonian(a,n);
	return 0;
}
void Hamiltonian(int*a,int n)
{
	int*path,i;
	path=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		*(path+i)=-1;

	*(path+0)=0;
	if(CycleFound(a,path,n,1)==1)
	{
		for(i=0;i<n;i++)
			printf("%d\t",*(path+i));

		printf("%d",*(path+0));
	}
	else
		printf("\nNo Hamiltonian cycle Found.");
}
int CycleFound(int*a,int*path,int n,int k)
{
	int i,j;
	if(k==n)
	{
		if(*(a+(*(path+k-1))*n+0)==1)
			return 1;
		else
			return 0;
	}
	for(i=1;i<n;i++)
	{
		if(isValid(a,path,i,k,n)==1)
		{
			*(path+k)=i;
			if(CycleFound(a,path,n,k+1)==1)
				return 1;
			else
				*(path+k)=-1;
		}

	}
	return 0;
}
int isValid(int*a,int*path,int i,int k,int n)
{
	int j;
	if(*(a+(*(path+k-1))*n+i)==0)
		return 0;
	else
	{
		for(j=0;j<k;j++)
		{
			if(*(path+j)==i)
				return 0;
		}
		return 1;
	}
}