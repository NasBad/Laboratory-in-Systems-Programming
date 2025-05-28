/*
** Name: Naseem Badran
*/
#include <stdio.h>

int my_rottate(unsigned int num,int r);
void printBin(int num);

int main()
{
	int r;
	unsigned int num;
	printf("insert number\n");
	scanf("%u",&num);
	printf("insert number of rottations\n");
	printf("(if to right then insert a positive number)\n");
	printf("(if to left then insert a negative number)\n");
	scanf("%d",&r);
 	printf("\n");
	printf("before:\n");
	printf("your number in Decimal:%u \n",num);
	printf("your number in Hex:%o \n",num);
	printf("your number in 16:%x \n",num);
	printf("your number in Binary:");
	printBin(num);
	printf("\n");


	num=my_rottate(num,r);


 	printf("\n");
	printf("after:\n");
	printf("your number in Decimal:%u \n",num);
	printf("your number in Hex:%o \n",num);
	printf("your number in 16:%x \n",num);
	printf("your number in Binary:");
	printBin(num);
	printf("\n");


	return 0;
}

int my_rottate(unsigned int num,int r)
{
	unsigned int mask1=1<<31;unsigned int mask2=1;int i=0;
	if(r>0)
	{
		for(i=0;i<r;i++)
		{
			if((num&mask2)==1)
			{
				num=num>>1;
				num=num|mask1;
			}
			else
			{
				num=num>>1;
			}
		}	
	}
	if(r<0)
	{
		for(i=0;i>r;i--)
		{
			if((num&mask1)==1)
			{
				num=num<<1;
				num=num|mask2;
			}
			else
			{
				num=num<<1;
			}
		}
	}
	if(r==0)
	{
		return num;
	}
	return num;
}


void printBin(int num)
{
	unsigned int mask= 1<<(32-1);
	
	while(mask)
	{
		if((num&mask)==0)
			printf("0");
		else
			printf("1");
		mask>>=1;
	}
}
