/*
Question: 

No twins pls !!!: Mr. Chitti, a robot is assigned a job of reporting to his boss Dr. Vaseegaran
about the existence of twins in a group. Chitti’s job is just to report whether the group is distinct 
or not. Even if one duplicate is present then the group is not unique. Help Mr. Chitti to report. 
Input: an array of integers 
output: Array distinct / Array not distinct
Example: Consider the following array. The array is not distinct as 10 is duplicated. 
Array: 2 6 10 14 18 10 3 7
*/
#include<stdio.h>
int main()
{
	int i,j,n,flag=0,a[1000];
	printf("Enter n value\n");
	scanf("%d",&n);
	printf("Enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				flag=1;
			}
		}
	}
	if(flag==1)
	{
		printf("Array is not distinct\n");
	}
	else
	{
		printf("Array is distinct\n");
	}

	return(0);
}