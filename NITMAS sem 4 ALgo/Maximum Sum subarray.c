#include<stdio.h>
#include<stdlib.h>
// maximum sum consecutive subarray

int main()
{
	int*a,n,i,k,s,s1,j;
	printf("\nEnter the size of array:- ");
	scanf("%d",&n);

	a=(int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		scanf("%d",(a+i));
	}
	printf("\nEnter the size of subarray:- ");
	scanf("%d",&k);
	
	
	s=0;
	for(i=0;i<n;i++)
	{
		
		s1=0;
		if(i+k<n)
		{
			for(j=i;j<i+k;j++)
				s1=s1+*(a+j);
		}
		if(s1>s)
			s=s1;
	}
	printf("\n%d",s);
	return 0;
}
