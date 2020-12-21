/*34.	given a string without strng length, find the reverse of string.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* reverse_a_string(char*);

void main(){
	char* given_string = (char*)malloc(sizeof(char*) * 50);
	printf("Please enter your string :");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	char* reverse_string = (char*)malloc(sizeof(char*) * (index+1));
	reverse_string = reverse_a_string(given_string);
	printf("%s", reverse_string);
	_getch();
}

char* reverse_a_string(char* given_string){
	int length = 0;
	
	while (given_string[length++] != '\0'){}
	char* reverse_string = (char*)malloc(sizeof(char*) * (length + 1));
	length-= 2;
	int index = 0;
	while (length >= 0){
		reverse_string[index++] = given_string[length--];
	}
	reverse_string[index] = '\0';
	return reverse_string;
}