/* 2.Remove vowels and non alphabets from a string. */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

void remove_Vowels_And_NonAlphabets(char*,int);
bool isAlpha(char);
bool isVowel(char);

void main(){
	char *given_string;
	char ch;
	int string_length;
	given_string = (char*)malloc(sizeof(char)*100);
	printf("Enter your string : ");
	for (string_length = 0; (ch = getchar()) != '\n'; string_length++)
		given_string[string_length] = ch;
	given_string[string_length] = '\0';
	remove_Vowels_And_NonAlphabets(given_string, string_length);
	printf("%s", given_string);
	_getch();
}

void remove_Vowels_And_NonAlphabets(char* given_string, int string_length){
	int  index1 = 0, index2 = 0, flag = 0;
	while (index2 < string_length){
		if (isAlpha(given_string[index2]) && !isVowel(given_string[index2])){
			given_string[index1++] = given_string[index2];
		}
		else{
			if (flag == 0)
				flag = 1;
		}
		index2++;
	}
	given_string[index1] = '\0';
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
