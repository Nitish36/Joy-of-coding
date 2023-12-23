#include<stdio.h>
#include<stdlib.h>
struct Array
{
	int *A;
	int length;
};
void Create_Array(struct Array *arr)
{
	int i;
	printf("Enter array length\n");
	scanf("%d",&arr->length);
	if(arr->length==0)
		{printf("Array length cannot be zero\n");return;}
	else
	{
		arr->A=(int*)malloc(arr->length*sizeof(int));
		printf("Enter array elements\n");
        for(i=0;i<arr->length;i++)
        {
        	scanf("%d",&arr->A[i]);
        }
	}
}
void Display(struct Array arr)
{
	int i;
	if(arr.length==0)
		{printf("Array is Khali\n");return;}
    for(i=0;i<arr.length;i++)
    	{printf("%d\t",arr.A[i]);}
    printf("\n");
}
void Swap(int *p,int *q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
int find_Max(struct Array *arr)
{
	int max=-32768,i;
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]>max)
			max=arr->A[i];
	}
	return max;
}
void Bubble_Sort(struct Array *arr)
{
	int i,j,n;
	n=arr->length;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr->A[j]>arr->A[j+1])
				Swap(&arr->A[j],&arr->A[j+1]);
		}
	}
	printf("Bubble_Sort done successfully....\n");
}
void Insertion_Sort(struct Array *arr)
{
	int i,x,j;
	for(i=1;i<arr->length;i++)
	{
		x=arr->A[i];
		j=i-1;
		while(j>-1 && arr->A[j]>x)
		{
			arr->A[j+1]=arr->A[j];j--;
		}
		arr->A[j+1]=x;
	}
	printf("Insertion_Sort done successfully....\n");
}
void Selection_Sort(struct Array *arr)
{
	int i,j,k,n;
	n=arr->length;
	for(i=0;i<n-1;i++)
	{
		for(j=k=i;j<n;j++)
		{
			if(arr->A[j]<arr->A[k])
				{k=j;}
		}
		Swap(&arr->A[i],&arr->A[k]);
	}
	printf("Selection_Sort done successfully....\n");
}
void Count_Sort(struct Array *arr)
{
	int i,max,j;
	max=find_Max(arr);
	int *C;
	C=(int*)malloc(arr->length*sizeof(int));
	for(i=0;i<(max+1);i++)
	{
		C[i]=0;
	}
	for(i=0;i<arr->length;i++)
	{
		C[arr->A[i]]++;
	}
	i=0,j=0;
	while(j<(max+1))
	{
		if(C[j]>0)
		{
			arr->A[i++]=j;
			C[j]--;
		}
		else
			j++;
	}
	printf("Count_Sort done successfully...\n");
}
void Merge(struct Array *arr,int l,int mid,int h)
{
    int i,j,k;
    i=l;j=mid+1;k=l;
    int *B;
    B=(int*)malloc(arr->length*sizeof(int));
    while(i<=mid && j<=h)
    {
        if(arr->A[i]<arr->A[j])
        	{B[k++]=arr->A[i++];}
        else
        	{B[k++]=arr->A[j++];}
    }
    for(;i<=mid;i++)
    	{B[k++]=arr->A[i];}
    for(;j<=h;j++)
    	{B[k++]=arr->A[j];}
    for(i=l;i<=h;i++)
    {
    	arr->A[i]=B[i];
    }
}
void Merge_Sort(struct Array *arr)
{
	int i,p,l,h,mid;
    int n=arr->length;
    for(p=2;p<=n;p=p*2)
    {
    	for(i=0;i+p-1<=n;i++)
    	{
    		l=i;
    		h=i+p-1;
    		mid=(l+h)/2;
    		Merge(arr,l,mid,h);
    	}
    }
    if(p/2<n)
    {
    	Merge(arr,0,p/2,n-1);
    }
    printf("Merge_Sort done successfully ....\n");
}
int main()
{
	struct Array arr;
	int ch;
	for(;;)
	{
		printf("1:Create_Array\n2:Bubble_Sort\n3:Insertion_Sort\n4:Selection_Sort\n5:Count_Sort\n6:Merge_Sort\n7:Display\n8:Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:Create_Array(&arr);break;
			case 2:Bubble_Sort(&arr);break;
			case 3:Insertion_Sort(&arr);break;
			case 4:Selection_Sort(&arr);break;
			case 5:Count_Sort(&arr);break;
			case 6:Merge_Sort(&arr);break;
			case 7:Display(arr);break;
			default:exit(0);
		}
	}
}