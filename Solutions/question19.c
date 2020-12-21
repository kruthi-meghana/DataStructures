/* 19.given two strings find out all common characters of the string.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void all_common_characters(char*, char*);

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

	all_common_characters(given_string1, given_string2);
	_getch();
}

void all_common_characters(char* given_string1, char* given_string2){
	int frequency[26] = { 0 }, index1 = 0;
	while (given_string1[index1] != '\0'){
			if (given_string1[index1] >= 97 && given_string1[index1] <= 122)
				frequency[given_string1[index1] - 97] += 1;
			else if (given_string1[index1] >= 65 && given_string1[index1] <= 90)
				frequency[given_string1[index1] - 65] += 1;
			index1 += 1;
	}
	for (index1 = 0; given_string2[index1] != '\0'; index1++){
		if (frequency[given_string2[index1] - 65] > 0)
			frequency[given_string2[index1] - 65] = -1;
		if (frequency[given_string2[index1] - 97] > 0)
			frequency[given_string2[index1] - 97] = -1;
	}
	for (int i = 0; i < 26; i++){
		if (frequency[i] == -1)
			printf("%c", i + 65);
	}
}