/*46.given a string, return the Kth index from the end of the string*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char get_kth_index_from_end(char* , int , int);

void main(){
	char* given_string = (char*)malloc(sizeof(char) * 500);
	printf("Enter your string:");
	char ch;
	int index = 0;
	for (; (ch = getchar()) != '\n';)
		given_string[index++] = ch;
	given_string[index] = '\0';
	int k_index;
	printf("enter your index");
	scanf("%d", &k_index);
	printf("%c :  is the character ", get_kth_index_from_end(given_string, index-1,k_index));
	_getch();
}

char get_kth_index_from_end(char* given_string, int length_of_string,int k_index){
	int count = 0;
	while (length_of_string >= 0){
		if (count == k_index)
			return given_string[length_of_string];
		count++;
		length_of_string -= 1;
	}
}