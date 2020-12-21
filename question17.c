/* 17.given a string find out which character appears more in that string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char character_frequency(char*);

void main(){
	char* given_string, ch;
	int index;
	given_string = (char*)malloc(sizeof(char) * 50);

	printf("Enter your string :");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		given_string[index] = ch;
	given_string[index] = '\0';
	
	printf("%c : is the frequency",character_frequency(given_string));
	_getch();
}

char character_frequency(char* given_string){
	int frequency[26] = { 0 };
	int index = 0;
	int ind;
	while (given_string[index] != '\0'){
		if (given_string[index] >= 97 && given_string[index] <= 122)
			frequency[given_string[index] - 97] += 1;
		else if (given_string[index] >= 65 && given_string[index] <= 90)
			frequency[given_string[index] - 65] += 1;
		index++;
			
	}
	int max = frequency[0], index_of_max_element = 0;
	for (ind = 1; ind < 26; ind++){
		if (max < frequency[ind]){
			max = frequency[ind];
			index_of_max_element = ind;
		}
	}
	return index_of_max_element + 97;
}