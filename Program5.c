#include<stdio.h>
int main()
{
	int n=3;
	int a[n][n],b[n][n];
	printf("Enter %dx%d matrix: \n",n,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("\n\nYou entered %dx%d matrix: \n",n,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i][j]=a[j][n-i-1];
		}
	}
	printf("\n\nRotated %dx%d matrix: \n",n,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
}