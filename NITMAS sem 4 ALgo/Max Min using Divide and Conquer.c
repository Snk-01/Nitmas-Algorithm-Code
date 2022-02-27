// array max element using divide and conquer


#include<stdio.h>
#include<stdlib.h>
int Find(int*,int,int,int);
int main()
{
	int *a,n,i;
	printf("\nEnter the size of array:- ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
		scanf("%d",(a+i));
	
	printf("\nThe maximum element is %d and minimum element is %d",(Find(a,0,n-1,0)),Find(a,0,n-1,1));

	return 0;
}
int Find(int*a,int l,int r,int k)
{
	int m,p,q;
	if(l<r)
	{
		m=(l+r)/2;
		p=Find(a,l,m,k);
		q=Find(a,m+1,r,k);

		if(p>q && !k || p<q && k )
			return p;
		else
			return q;
	}
	else
		return *(a+l);
}