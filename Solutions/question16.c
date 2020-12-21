/*16.given two strings as input, find out positions where characters of both strings are same.
you need to print all such positions and the characters*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void find_positions(char*, char*);

void main(){
	char* given_string1, *given_string2, ch;
	int index;
	given_string1 = (char*)malloc(sizeof(char) * 50);
	given_string2 = (char*)malloc(sizeof(char) * 50);
	
	printf("Enter your first string:");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		given_string1[index] = ch;
	given_string1[index] = '\0';

	printf("Enter your second string:");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		given_string2[index] = ch;
	given_string2[index] = '\0';
	
	find_positions(given_string1, given_string2);
	_getch();
}

void find_positions(char* given_string1, char* given_string2){
	int index = 0;
	while (given_string1[index] != '\0' && given_string2[index] != '\0'){
		if (given_string1[index] == given_string2[index])
			printf("%d \n", index);
		index++;
	}
}