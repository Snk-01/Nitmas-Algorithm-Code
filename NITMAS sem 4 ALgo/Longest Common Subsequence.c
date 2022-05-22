#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
ABCBDAB
BDCABA

AGGTAB
GXTXAYB
*/

int match(char,char);
int main()
{
	char x[20],y[20];
	int dp[21][21],i,j;
	printf("\nEnter the first string:- ");
	gets(x);
	printf("\nEnter the second string:-  ");
	gets(y);

	for(i=0;i<21;i++)
	{
		for(j=0;j<21;j++)
		{
			dp[i][j]=0;
		}
	}
	for(i=1;i<=strlen(y);i++)
	{
		for(j=1;j<=strlen(x);j++)
		{
			if(dp[i][j-1]>(dp[i-1][j]+match(x[j-1],y[i-1])))
				dp[i][j]=dp[i][j-1];
			else
				dp[i][j]=dp[i-1][j]+match(x[j-1],y[i-1]);

		}
	}

	for(i=1;i<=strlen(y);i++)
	{
		for(j=1;j<=strlen(x);j++)
		{
			printf("%d\t",dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",dp[strlen(y)][strlen(x)]);
	return 0;
}
int match(char x,char y)
{
	if(x==y)
		return 1;
	else
		return 0;
}