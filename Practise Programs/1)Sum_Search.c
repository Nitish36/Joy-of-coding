#include<stdio.h>
#include<stdlib.h>
void Swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
void Sort(int *A,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
				{Swap(&A[j],&A[j+1]);}
		}
	}
}
void Sum_Search(int *A,int n,int sum)
{
	Sort(A,n);
	int low,high;
	low=0;
	high=n-1;
	while(low<=high)
	{
		if((A[low]+A[high])==sum)
		{
			printf("Match found\n");
			printf("Pairs are %d and %d\n",A[low],A[high]);
			return;}
		else if((A[low]+A[high])<sum)
			{low++;}
		else
			{high--;}
	}
	printf("Match not found\n");
}
int main()
{
	int *A,n,i,sum=0;
	printf("Enter the length of the array\n");
	scanf("%d",&n);
	A=(int*)malloc(n*sizeof(int));
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Enter a sum value\n");
	scanf("%d",&sum);
	Sum_Search(A,n,sum);
	return(0);
}