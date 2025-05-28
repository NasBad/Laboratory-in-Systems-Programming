/*
** Name: Naseem Badran
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int short_string(char str1[]);
int main()
{
	char str1[]="";
	printf("enter string to shorten in:\n");
	scanf("%s",&str1);
	printf("\n original string: %s \n",str1);
	short_string(str1);
	printf("\n shorten string: %s \n",str1);
	return 0;
}
int short_string(char str1[])
{
	int i=0;int f=0;
	if(strlen(str1)<1 || strlen(str1)>80)
	{
		printf("\nstring is not good");
		
	}
	while(i<strlen(str1))
	{
		
		if(isalpha(str1[i])!=0)
		{	
			int j=i;
				int x=str1[i];
				int y=str1[i+1];
				int z=str1[i+2];
				if(y-x==1 && z-y==1)
				{
					f=j;
					j+=2;
					while(str1[j]+1==str1[j+1])
					{
						j++;
						
					}
					str1[f+1]='-';
					str1[f+2]=str1[j];
					while(j<strlen(str1))
					{
						str1[f+2]=str1[j+1];
						f++;
						j++;
						
					}
				}
				else
				{
					i++;
				}
		}
		else
		{
			i++;
		}	
	}
}
