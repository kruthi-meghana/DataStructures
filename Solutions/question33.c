/*33.given a string, return the number of consonants and vowels in the given string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

int get_count_of_vowels(char*);
bool isVowel(char);
bool isAlpha(char);

void main(){
	char* given_string = (char*)malloc(sizeof(char*) * 50);
	printf("Please enter your string :");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';

	printf("%d is the number of vowels", get_count_of_vowels(given_string));
	_getch();
}

int get_count_of_vowels(char* given_string){
	int index = 0, number_of_vowels = 0, number_of_consonants =0 ;
	while (given_string[index] != '\0'){
		if (isAlpha(given_string[index])){
			if (isVowel(given_string[index]))
				number_of_vowels += 1;
			else
				number_of_consonants += 1;
		}
		index += 1;
	}
	printf("%d is number of consonants", number_of_consonants);
	return number_of_vowels;
}

bool isVowel(char character){
	switch (character){
	case 'a': return true;
	case 'e': return true;
	case 'i': return true;
	case 'o': return true;
	case 'u': return true;
	case 'A': return true;
	case 'E': return true;
	case 'I': return true;
	case 'O': return true;
	case 'U': return true;
	default: return false;
	}
}

bool isAlpha(char character){
	if ((character >= 'a'&& character <= 'z') || (character >= 'A' && character <= 'Z'))
		return true;
	return false;
}