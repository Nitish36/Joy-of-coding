#include<stdio.h>
int main()
{
	int n;
	printf("Enter number of balloons: \n");
	scanf("%d",&n);
	int arr[1000],freq[10]=n;
	printf("Enter balloons numbers: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		if(freq[arr[i]]==0)
			freq[arr[i]]=1;
	}
	printf("balloons numbered");
	for(i=0;i<10;i++)
	{
		if(freq[i]==1)
			printf("%d\n",i );
	}
	printf("\b\b\n");
}