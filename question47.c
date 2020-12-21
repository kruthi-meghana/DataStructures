/*47.given a string, return the number of words in the string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int get_word_count(char*);
void main(){
	char* given_string = (char*)malloc(sizeof(char) * 500);
	printf("Enter your string:");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	printf("%d is the count of words ", get_word_count(given_string));
	_getch();
}

int get_word_count(char* given_string){
	int index = 0, number_of_words = 0;
	while (given_string[index] != '\0'){
		if (given_string[index] == ' ')
			number_of_words += 1;
		index++;
	}
	return number_of_words + 1;
}