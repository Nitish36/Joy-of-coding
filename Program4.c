#include<stdio.h>
int main()
{
	int n,i,j,a[1000],sum,K,index1=0,index2=0;
	printf("Enter size of the array\n");
	scanf("%d",&n);
	printf("Enter %d elements: \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter number to be compared\n");
	scanf("%d",&K);
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>0;j--)
		{
			sum=a[i]+a[j];
			if(sum==K)
			{
				index1=i;
				index2=j;
			}
		}
	}
	printf("Indexes are %d and %d\n",index1,index2);
}