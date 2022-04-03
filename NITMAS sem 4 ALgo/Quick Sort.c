//0th element is the pivot



 

#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 10e7

void FloyedWarshall(int *adjmat, int v, int **A, int **S){
	int i,j,k,dis;
	A=(int**)calloc((v+1),sizeof(int*));
	S=(int**)calloc((v+1),sizeof(int*));
	for(i=0;i<=v;i++){
		A[i]=(int*)calloc(v*v,sizeof(int));
		S[i]=(int*)calloc(v*v,sizeof(int));
	}
	for(i=0;i<v*v;i++)
		*(A[0]+i)=adjmat[i];
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			*(S[0]+i*v+j)=i;

	for(i=1;i<=v;i++){//step number
		for(j=0;j<v;j++){
			for(k=0;k<v;k++){
				dis=*(A[i-1]+v*j+(i-1))+*(A[i-1]+v*(i-1)+k);
				if(dis<*(A[i-1]+v*j+k)){
					*(A[i]+v*j+k)=dis;
					*(S[i]+v*j+k)=i-1;
				}else{
					*(A[i]+v*j+k)=*(A[i-1]+v*j+k);
					*(S[i]+v*j+k)=*(S[i-1]+v*j+k);
				}
			}
		}
	}
	//printing of the final matrices
	printf("The Final Distance Matrix is:\n\t");
	for(i=0;i<v;i++)
		printf("(%d)\t",i+1);
	//puts("");
	for(i=0;i<v;i++){
		printf("\n(%d)\t",i+1);
		for(j=0;j<v;j++){
			if(*(*(A+v)+v*i+j)==INT_MAX)printf("INF\t");
			else printf("%d\t",*(A[v]+v*i+j));
		}
	}

	printf("\nThe Final Source Matrix is:\n\t");
	for(i=0;i<v;i++)
		printf("(%d)\t",i+1);
	for(i=0;i<v;i++){
		printf("\n(%d)\t",i+1);
		for(j=0;j<v;j++){
			if(i==j)
				printf("-\t");
			else printf("%d\t",*(S[v]+v*i+j)+1);
		}
	}
}

int main(){
	int v,e,*adjmat,i,a,b,d;
	int **A,**S;
	printf("Enter the number of vertices and edges:");
	scanf("%d%d",&v,&e);
	adjmat=(int*)malloc(v*v*sizeof(int));
	for(i=0;i<v*v;i++) adjmat[i]=INT_MAX;//initalized with INF
	for(i=0;i<v;i++) adjmat[i*v+i]=0;//diagonal should be 0
	printf("Enter the Edges and distance:\n");
	while(e--){
		scanf("%d%d%d",&a,&b,&d);
		a--;
		b--;
		adjmat[a*v+b]=d;
		//adjmat[b*v+a]=d;
	}
	
	FloyedWarshall(adjmat,v,A,S);
}
//TIME COMPLEXITY=O(n^3)
//This is the program with nodes naming starting from 1, for nodes strting from 0 it is done in dp folder
/*
3 1
1 2 8
*/

/*#include<stdio.h>
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
		scanf("%d", (a + i));
	
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
		printf("%d\t", *(a + i));
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
}*/