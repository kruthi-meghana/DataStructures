/*7.write a function to find the length of a given string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
	char* given_string;
	char ch;
	given_string = (char*)malloc(sizeof(char) * 50);
	int i = 0;
	for (i = 0; (ch = getchar()) != '\n'; i++)
		given_string[i] = ch;
	given_string[i] = '\0';
	int string_length = length_of_string(given_string);
	printf("%d : is the length of string", string_length);
	_getch();
}

int length_of_string(char* given_string){
	int length = 0;
	while (given_string[length++] != '\0'){
	}
	return length - 1;
}