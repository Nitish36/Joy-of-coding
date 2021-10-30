#include<stdio.h>
int main()
{
	char str[100];
	printf("Enter string: ");
	scanf("%[^\n]s", str);
	printf("Abbreviation: %c",str[0]);
		for(int i=0;str[i]!='\0';i++)
			if(str[i]==' ' && str[++i]>=65 && str[i]<=90)
			printf("%c",str[i]);
		printf("\n");
}