/*32.Given a string, return the Kth index in a string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char  get_character(char* given_string, int index);
void main(){
	char* given_string = (char*)malloc(sizeof(char*) * 50);
	printf("Please enter your string :");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	printf("Enter your index :");
	scanf("%d", &index);
	printf("%c is the character at %d index", get_character(given_string, index - 1), index);
	_getch();
}

char  get_character(char* given_string, int index){
	int ind = 0;
	while (given_string[ind] != given_string[index] && given_string[ind] != '\0'){
		ind += 1;
	}
	return given_string[ind];
}