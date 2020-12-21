/*43.given a string, count the frequency of a given word*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int frequency_of_word(char*, char*);

void main(){
	char* given_string = (char*)malloc(sizeof(char)*500);
	printf("Enter your string:");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	int length_of_sentence = index;
	char* given_word = (char*)malloc(sizeof(char) * 50);
	printf("Enter your word :");
	index = 0;
	for (; (ch = getchar()) != '\n';)
		given_word[index++] = ch;
	given_word[index] = '\0';
	printf("%d", frequency_of_word(given_string, given_word, length_of_sentence));
	_getch();
}

int frequency_of_word(char* given_string, char* word, int length_of_sentence){
	int index = 0, flag = 0;
	int index2 = 0, frequency = 0;
	while (given_string[index] != '\0' || index < length_of_sentence){
		index2 = 0;
		flag = 0;
		while (word[index2] != '\0' && given_string[index] != '\0'){
			if (word[index2] != given_string[index]){
				flag = 1;
			}
			index2 += 1;
			index += 1;
		}
		if (flag == 0)
			frequency += 1;		 
		index += 1;
	}
	return frequency;
}