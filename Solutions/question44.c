/*44.given a string, return the first word of the string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* get_first_word(char*);

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
	printf("%s", get_first_word(given_string));
	_getch();
}

char* get_first_word(char* given_string){
	int index = 0;
	char* word = (char*)malloc(sizeof(char) * 10);
	while (given_string[index] != '\0'){
		if (given_string[index] == ' '){
			word[index] = '\0';
			return word;
		}
		word[index] = given_string[index];
		index += 1;
	}
	return word;
}