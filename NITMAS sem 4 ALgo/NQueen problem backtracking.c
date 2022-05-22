#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void display(int*,int);
int place(int*,int,int);
void NQueen(int*,int,int);
int main()
{
	int*x,n;
	printf("\nEnter the size of chessboard:- ");
	scanf("%d",&n);
	x=(int*)calloc(n,sizeof(int));
	printf("The ways in which the queens can be placed in chessboard:\n");
	NQueen(x,0,n);
	return 0;
}
void NQueen(int*x,int k,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(place(x,k,i))
		{
			*(x+k)=i;
			if(k==n-1)
				display(x,n);
			else
				NQueen(x,k+1,n);
		}
	}
}
int place(int*x,int k,int i)
{
	int j;
	for(j=0;j<=k-1;j++)
	{
		if(*(x+j)==i || abs(*(x+j)-i)==abs(j-k))
			return 0;
	}
	return 1;
}
void display(int*x,int n)
{
	printf("\n");
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",*(x+i));
}