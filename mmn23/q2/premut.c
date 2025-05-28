/*Naseem Badran
* ID:322726662
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 30
#define MAX_DICTIONARY_WORDS 10000

/*counts the sum of the chars in the string
	for example"the word chair is 
	c+h+a+i+r=99+104+97+105+114=519"
	the function returns i if the sum of 2 words is equal and -1 if its not equal*/
int anagram(char* word1, char* word2) {
	int i; int j;
	int count1=0; int count2=0;		
	for (i = 0; i < strlen(word1); i++) {
		count1=count1+word1[i];
		/*printf("tester 1:%d\n",count1);*/
	}
	for(i=0;i<strlen(word2);i++)
	{
		for(j=i;j<strlen(word1);j++)
		{
			count2=count2+word2[j];
			/*printf("tester 2:%d\n",count2);*/
			if(count2==count1)
			{
				return i;
			}	
		}
		count2=0;
	}

    return -1;
}
/*this function reads the file (text) and calls the function (anagram) then prints the word if n is not equal to -1*/
void find_anagrams(char* word) {
    int n=-1;
    int i;
    FILE* fp = fopen("text.txt", "r");
    char str_out[MAX_WORD_LENGTH];
    char dict_word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", dict_word) != EOF) {
        n=anagram(word, dict_word);
	/*printf("tester n:%d\n",n);*/
	if(n!=-1)
	{
	    strncpy(str_out,dict_word+n,strlen(word));
	    for(i=0;i<strlen(word);i++)
		printf("%c",str_out[i]);
            printf("\n");
        }
    }
    fclose(fp);
}


int main() {
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);
    printf("Anagrams of %s: \n", word);
    find_anagrams(word);
    return 0;
}

