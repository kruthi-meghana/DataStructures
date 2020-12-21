/*45.given a string, return the last word in the string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* get_first_word(char*,int);

void main(){

	char* given_string = (char*)malloc(sizeof(char) * 500);
	printf("Enter your string:");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	int length_of_sentence = index;

	char* given_word = (char*)malloc(sizeof(char) * 50);
	printf("%s", get_first_word(given_string, length_of_sentence));
	_getch();
}

char* get_first_word(char* given_string,int length_of_sentence){
	int index = length_of_sentence - 1;
	char* word = (char*)malloc(sizeof(char) * 10);
	while (given_string[index] >= 0){
		if (given_string[index] == ' ' || index == 0){
			break;
		}
		index -= 1;
	}
	if (index != 0)
		index += 1;
	int ind = 0;
	for (; given_string[index] != '\0'; index++)
		word[ind++] = given_string[index];
	word[ind] = '\0';
	return word;
}