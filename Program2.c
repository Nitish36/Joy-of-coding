#include<stdio.h>
int main()
{
	int n, count=0, temp;
	printf("Enter the number of elements in array: ");
	scanf("%d",&n);
	int arr[1000];
	printf("Enter the elements of the array: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=-999)
		{
			temp=arr[i];
			printf("%d occurs: ",temp);
			for(int j=0;j<n;j++)
			{
				if(temp==arr[j])
				{
					count++;
					arr[j]=-999;
				}
			}
			printf(" %d times\n",count);
			count=0;
		}

	}
}