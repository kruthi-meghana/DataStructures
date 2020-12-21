/*31.given a string, return the length of the string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
	char* given_string = (char*)malloc(sizeof(char*) * 50);
	printf("Please enter your string :");
	scanf("%s", given_string);
	printf("%d",length_of_string(given_string));
	_getch();
}

int length_of_string(char* given_string){
	int index = 0;
	while (given_string[index++] != '\0'){
	}
	return index - 1;
}