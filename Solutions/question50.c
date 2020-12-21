/*50.given two numbers as strings, find the max number out of the two.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isFirstGreater(char*, char*);

void main(){
	char* str1, *str2, ch;
	int index = 0;
	str1 = (char*)malloc(sizeof(char) * 20);
	str2 = (char*)malloc(sizeof(char) * 20);

	printf("Enter your first number :");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		str1[index] = ch;
	str1[index] = '\0';

	printf("Enter your second number :");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		str2[index] = ch;
	str2[index] = '\0';

	if (isFirstGreater(str1, str2))
		printf("%s is the greatest number", str1);
	else
		printf("%s is the greatest number", str2);
	_getch();
}

bool isFirstGreater(char* str1, char* str2){
	int index = 0, length_str1 = length(str1), length_str2 = length(str2);
	if (str1[0] == '-' && str2[0] != '-')
		return false;
	if (str1[0] != '-' && str2[0] == '-')
		return true;
	if (length_str1 > length_str2)
		return true;
	else if (length_str1 < length_str2)
		return false;
	while (str1[index] != '\0'){
		if (str1[index] > str2[index]){
			if (str1[0] == '-')
				return false;
			return true;
		}

		if (str1[index] < str2[index]){
			if (str1[0] == '-')
				return true;
			return false;
		}
		index++;
	}
}

int length(char* str){
	int count = 0;
	while (str[count++] != '\0'){}
	return count;
}