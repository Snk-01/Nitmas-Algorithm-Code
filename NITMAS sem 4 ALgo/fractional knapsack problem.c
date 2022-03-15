/*The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weigh W such that the total value obtained is maximized.
Note:We can either take the item as a whole or break it into smaller units.
	Example:

Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.
30+20=50
120+100=220

30+10+10=50
120+60+50=230

10+20+20
60+100+80=240



20	100
10	50

20+10+20=50
30 120
20 80
Output: 240.00

Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00*/
/*3
25.0 24.0 15.0
18.0 15.0 10.0
20.0
*/
#include<stdio.h>
#include<stdlib.h>
float knapsack(int,float*,float*,float);
void swap(float*,int);
int main()
{
	float w,*val,*wt;
	int n,i;
	printf("\nEnter the knapsack capacity:- ");
	scanf("%d",&n);
	val=(float*)malloc(n*sizeof(float));
	wt=(float*)malloc(n*sizeof(float));

	printf("\nEnter the profit list:\n");
	for(i=0;i<n;i++)
		scanf("%f",(val+i));

	printf("\nEnter the weight list:\n");
	for(i=0;i<n;i++)
		scanf("%f",(wt+i));

	printf("\nEnter the weight limit:- ");
	scanf("%f",&w);

	printf("\nThe maximum profit is:- %.2f",knapsack(n,val,wt,w));
	return 0;
}
float knapsack(int n,float *val,float *wt,float w)
{
	float*a=(float*)malloc(n*sizeof(float)),s=0.0;
	int i,j;

	for(i=0;i<n;i++)
	{
		*(a+i)=*(val+i)/(*(wt+i));
	}
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
			if(*(a+j)<*(a+j+1))
			{
				swap(a,j);
				swap(wt,j);
				swap(val,j);
			}
	i=0;
	while(1)
	{
		if(*(wt+i)<=w)
		{
			s+=*(val+i);
			w-=*(wt+i);
		}
		else
		{
			s+=w*(*(a+i));
			break;
		}
		i++;
	}
	return s;
}
void swap(float*a,int j)
{
	float temp;
	temp=*(a+j);
	*(a+j)=*(a+j+1);
	*(a+j+1)=temp;
}