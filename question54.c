/*54.given two strings, find the words that are common to both the strings*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
bool compare_strings(char* , char* );
void main(){
	char* given_string_1, *given_string_2;
	given_string_1 = (char*)malloc(sizeof(char) * 150);
	given_string_2 = (char*)malloc(sizeof(char) * 150);

	printf("Enter your first string");
	char ch;
	int index;
	for (index = 0; (ch = getchar()) != '\n'; index++){
		given_string_1[index] = ch;
	}
	given_string_1[index] = '\0';
	printf("Enter your second string");
	for (index = 0; (ch = getchar()) != '\n'; index++){
		given_string_2[index] = ch;
	}
	given_string_2[index] = '\0';
	char* word = (char*)malloc(sizeof(char) * 50);
	int word_index = 0;
	for (int index = 0; given_string_1[index] != '\0'; index++){
		if (given_string_1[index] == ' '){
			word[word_index] = '\0';
			word_index = 0;
			if (compare_strings(given_string_2, word))
				printf("%s \n", word);
			index += 1;
		}
		word[word_index++] = given_string_1[index];
	}
	word[word_index] = '\0';
	if (compare_strings(given_string_2, word))
		printf("%s \n", word);
	_getch();
}

bool compare_strings(char* given_string_2, char* word){
	int index = 0;
	int word_index = 0;
	while (given_string_2[index] != '\0'){
		if (word[word_index] == '\0' && given_string_2[index] == ' ')
			return true;
		if ((word[word_index] != given_string_2[index]) || (word[word_index] == '\0' && given_string_2[index] != ' ') || (given_string_2[index] == ' ' && word[word_index] != '\0')){
			for (; given_string_2[index] != ' ' && given_string_2[index] != '\0'; index++){}
			if (given_string_2[index] != '\0')
				index += 1;
			word_index = 0;
			continue;
		} 
		
		index += 1;
		word_index += 1;
	}
	if (word[word_index] == '\0')
		return true;
	return false;

}