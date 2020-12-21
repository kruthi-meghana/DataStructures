/*53.given an array of words, find all palindrome words in that array.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

int get_length(char*);
bool isPalindrome(char*);

void main(){
	char **array_of_words;

	int number_of_elements = 0;
	printf("Enter number of words :");
	scanf("%d", &number_of_elements);

	array_of_words = (char**)malloc(sizeof(char*) * number_of_elements);
	
	for (int index = 0; index < number_of_elements; ++index)
		array_of_words[index] = (char*)malloc(sizeof(char) * 51);
	
	for (int index = 0; index < number_of_elements; ++index)
		scanf("%s", array_of_words[index]);

	for (int index = 0; index < number_of_elements; index++){
		if (isPalindrome(array_of_words[index]))
			printf("%s : is plaindrome \n", array_of_words[index]);
	}
	
	_getch();
}
int get_length(char* given_word){
	int index = 0;
	while (given_word[index++] != '\0'){}
	return index - 1;
}
bool isPalindrome(char* given_word){
	int index = 0;
	int length = get_length(given_word) - 1;
	while (index < length){
		if (given_word[index] != given_word[length])
			return false;
		index += 1;
		length -= 1;
	}
	return true;
}