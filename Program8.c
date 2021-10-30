#include<stdio.h>
int main()
{
	int freq[27]={0}, max=0, maxindex=0;
	char str[100];
	printf("Enter string: ");
	scanf("%[^\n]s", str);
	for(int i=0;str[i]!='\0';i++)
		freq[str[i]-97]++;

	for(int i=0;i<27;i++)
	{
		if(freq[i]>max)
		{
			max=freq[i];
			maxindex=i;
		}
	}
	for(int i=0;i<27;i++)
		if(freq[i]==max)
			printf("%c occurs %d times\n",(97+maxindex),max);
}