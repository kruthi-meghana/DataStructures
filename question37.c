/*37.given a string, remove extra spaces btw each word.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* remove_spaces(char* , int );

void main(){
	char* given_string = (char*)malloc(sizeof(char*) * 150);
	printf("Please enter your string :");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	printf("%s", remove_spaces(given_string, index));
	_getch();
}

char* remove_spaces(char* given_string, int length){
	char* blank = (char*)malloc(sizeof(char*) * length);
	int index = 0, count = 0;
	length = 0;
	while (given_string[length] != '\0'){
		if (given_string[length] != ' '){
			blank[index++] = given_string[length];
			count = 0;
		}			
		else{
			if (count == 0){
				blank[index++] = given_string[length];
				count = 1;
			}
				
		}
		length += 1;
	}
	blank[index] = '\0';
	return blank;
}