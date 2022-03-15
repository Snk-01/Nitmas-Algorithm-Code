
/* 6
5 3 3 2 4 2
200 180 190 300 120 100

4
2 1 2 3
40 30 20 10
*/


#include<stdio.h>
#include<stdlib.h>
int job_sequencing(int,int*,int*);
void swap(int*,int);
int main()
{
	int*dl,*p,n,i;
	printf("\nEnter the number of jobs:- ");
	scanf("%d",&n);
	dl=(int*)malloc(n*sizeof(int));
	p=(int*)malloc(n*sizeof(int));

	printf("\nEnter the deadlines:");
	for(i=0;i<n;i++)
		scanf("%d",(dl+i));

	printf("\nEnter the profit lists:");
	for(i=0;i<n;i++)
		scanf("%d",(p+i));

	printf("\nThe maximum profit is:- %d",job_sequencing(n,dl,p));
	return 0;
}
int job_sequencing(int n,int*dl,int*p)
{
	int i,j,*a,m,k,s=0;
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
			if(*(p+j)<*(p+j+1))
			{
				swap(p,j);
				swap(dl,j);
			}
	m=0;
	for(i=0;i<n;i++)
		if(*(dl+i)>m)
			m=*(dl+i);

	a=(int*)calloc(m,sizeof(int));
	for(i=0;i<n;i++)
	{
		k=*(dl+i)-1;
		if(*(a+k)==0)
			*(a+k)=*(p+i);
		else
		{
			for(j=0;j<k;j++)
				if(*(a+j)==0)
				{
					*(a+j)=*(p+i);
					break;
				}
		}
	}
	for(i=0;i<m;i++)
	{
		printf("%d\t",*(a+i));
		s+=*(a+i);
	}

	return s;
}
void swap(int*a,int j)
{
	float temp;
	temp=*(a+j);
	*(a+j)=*(a+j+1);
	*(a+j+1)=temp;
}