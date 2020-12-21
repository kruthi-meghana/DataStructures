/*36.given a string, reverse the word sequence.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* reverse_word_sequence(char*, int);
int get_last_word_index(char*, int);

void main(){
	char* given_string = (char*)malloc(sizeof(char*) * 150);
	printf("Please enter your string :");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	printf("%s", reverse_word_sequence(given_string, index));
	_getch();
}

char* reverse_word_sequence(char* given_string, int length){
	char* reverse_sequence = (char*)malloc(sizeof(char*) * length);
	length -= 1;
	int index_reverse = 0;
	while (length > 0){
		int index = get_last_word_index(given_string,length);
		if (index != 0)
			index += 1;
		for (int i = index; i <= length; i++)
			reverse_sequence[index_reverse++] = given_string[i];
		reverse_sequence[index_reverse++] = ' ';
		length = index - 2;
	}
	reverse_sequence[index_reverse] = '\0';
	return reverse_sequence;
}

int get_last_word_index(char* given_string, int index){
	while (given_string[index] != ' ' && index > 0){ index--;}
	return index;
}