/*18.given a string find the ascii value sum of the characters*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
	char* given_string, ch;
	int index;
	given_string = (char*)malloc(sizeof(char) * 50);

	printf("Enter your string :");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		given_string[index] = ch;
	given_string[index] = '\0';

	printf("%d is the ASCII sum of all characters in string", ascii_sum(given_string));
	_getch();
}

int ascii_sum(char* given_string){
	int asci_sum = 0, index = 0;
	while (given_string[index] != '\0')
		asci_sum += given_string[index++];
	return asci_sum;
}