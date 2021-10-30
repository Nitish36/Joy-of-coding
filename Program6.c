#include<stdio.h>
int main()
{
	int n, k, sum=0, j=0, count=0, flag=0;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d elements: \n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("Enter an integer k: ");
	scanf("%d",&k);

	for(int i=0;i<n;i++)
	{
		j=i;
		sum=0;
		count=0;
		while(sum<k)
		{
			sum+=a[j++];
			count++;
		}
		if(sum==k)
		{
			flag=1;
			printf("The sub array is [");
			for(int l=i;l<i+count;l++)
				printf("%d, ",a[l]);
				printf("\b\b]\n");

			printf("Indices range from %d to %d\n",i,i+count-1);
			return 0;
		}
	}
		if(!flag)
		printf("Not possible to obtain the sum\n");
}