/*
** Name: Naseem Badran
*/

#include <stdio.h>
#include <string.h>

#define SIZE 512

int my_bcmp(char *b1,char *b2,int len);


int main()
{
	char str[SIZE]="";
	int a;int b;int len;int test=1;
	char *b1;
	char *b2;
	
	printf("\n enter len:");
	scanf("%d",&len);

	printf("\n b1:");
	scanf("%d",&a);

	printf("\n b2:");
	scanf("%d",&b);

	printf("\n enter string:");
	scanf("%s",&str);

	b1=&str[a];
	b2=&str[b];

	if(len>strlen(str))
	{
		printf("len is bigger than the length of the string ");
		test=1;
	}

	if(a>strlen(str))
	{
		test=1;
		printf("b1 is out of the string ");
	}

	if(b>strlen(str))
	{
		test=1;
		printf("b2 is out of the string ");
	}
	if(len<strlen(str) && a<strlen(str) && b<strlen(str))
	{
		test=my_bcmp(b1,b2,len);
	}




	/**tester*/
	if(test==1)
		printf("\nerror\n");

	if(test==0)
		printf("\npass\n");

return 0;
}

int my_bcmp(char *b1,char *b2,int len)
{
	char x=*b1;
	char y=*b2;
	int v;
	if(len==0)
	{
		return 0;
	}
	if(x=='\0' || y=='\0')
	{
		printf("pointer is out of the string\n");
		return 1;
	}
	if(x == y)
	{
		printf("%c equals %c\n",x,y);
		v=my_bcmp(b1+1,b2+1,len-1);
	}
	if(v==0)
	{
		return 0;
	}
	return 1;
}
