/*48.given a string, return the substring from i to J where i and J are inputs*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char* get_substring(char*, int, int);

void main(){
	char* given_string = (char*)malloc(sizeof(char) * 500);
	printf("Enter your string:");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	int ith_index, jth_index;
	printf("Enter your indices :");
	scanf("%d %d", &ith_index, &jth_index);
	printf("%s is the count of words ", get_substring(given_string,ith_index,jth_index));
	_getch();
}

char* get_substring(char* given_string, int ith_index, int jth_index){
	char* sub_string = (char*)malloc(sizeof(char)*(jth_index - ith_index));
	int index = 0;
	while (ith_index <= jth_index){
		sub_string[index++] = given_string[ith_index++];
	}
	sub_string[index] = '\0';
	return sub_string;
}