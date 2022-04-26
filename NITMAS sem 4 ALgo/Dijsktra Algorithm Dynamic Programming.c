#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
8 16
0 2 2
0 1 1
1 2 1
1 3 5
1 4 2
2 5 4
2 4 1
2 3 2
3 4 3
3 6 8
3 5 6
4 5 3
4 6 7
5 6 5
5 7 2
6 7 6
1
*/

/*
5 8
0 1 5
0 2 3
0 3 10
0 4 9
1 2 1
2 3 4
3 1 2
3 4 1
1
*/


struct vertex
{
	int selected,source,cost;
	//selected=0: not selected; 1:selected but temporary; 2: selected and permanent
};

void SSSP(struct vertex *vt,int v,int*a ,int s)
{
	int lp,i,j,k,min;
	vt[s].selected=2;
	lp=s;
	for(i=2;i<v;i++)//step number
	{
		for(j=1;j<v;j++)
		{
			if(*(a+lp*10+j)!=0 && (vt[j].selected==0 || (vt[j].selected==1 && ( *(a+lp*10+j)+vt[lp].cost ) < vt[j].cost)) )
			{
				vt[j].selected=1;
				vt[j].source=lp;
				vt[j].cost=*(a+lp*10+j)+vt[lp].cost;
				//printf("\ncost=%d",vt[j].cost);
			}

		}
		/*printf("\nStep %d:",i);
		for(j=1;j<v;j++)
		{
			if(vt[j].selected>0)
				printf("\t[%d,%d,%d]",j,vt[j].selected,vt[j].cost);
		}
		puts("");*/
		
		min=INT_MAX,k=-1;
		for(j=1;j<v;j++)
		{
			if(vt[j].selected==1 && vt[j].cost<min)
			{
				min=vt[j].cost;
				k=j;
			}
		}
		vt[k].selected=2;
		lp=k;
	}
	printf("Node\t[source,cost]\n");
	for(i=1;i<v;i++)
	{
		printf("%d\t [%d, %d]\n",i,vt[i].cost,vt[i].source);
	}

}

int main()
{
	struct vertex* vt;
	int*a,i ,j,v,e,w,k,*d,s;
	a=(int*)calloc(10*10,sizeof(int));
	printf("\nEnter the number of vertices and edges in the graph:- ");
	scanf("%d %d",&v,&e);

	printf("\nEnter the edges:\n");
	while(e!=0)
	{
		scanf("%d %d %d",&i,&j,&w);
		i++;j++;
		*(a+i*10+j)=w;
		e--;
	}
	v++;
	vt=(struct vertex*)malloc(v*sizeof(struct vertex));

	printf("\nEnter the source:- ");
	scanf("%d",&s);
	vt[s].source=-1;
	for(i=1;i<v;i++)
	{
		vt[i].selected=0;
	}
	
	SSSP(vt,v,a,s);


	return 0;
}
