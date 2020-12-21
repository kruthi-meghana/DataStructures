/*24.given two binary numbers as strings, write an adder. strings can be of different length*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char result[22];
int index = 0;

int adder_of_binary_numbers(char* str1, char* str2,  int length_1, int length_2);
char add_binary_digits(char num1, char num2, char carry,  int index);

void main(){
	char* str1, *str2, ch;
	int ind = 0;
	str1  = (char*)malloc(sizeof(char) * 20);
	str2 = (char*)malloc(sizeof(char) * 20);
	printf("Enter your first number");
	for (ind = 0; (ch = getchar()) != '\n'; ind++)
		str1[ind] = ch;
	str1[ind] = '\0';
	int length_1 = ind;
	printf("Enter your second number");
	for (ind = 0; (ch = getchar()) != '\n'; ind++)
		str2[ind] = ch;
	str2[ind] = '\0';
	
	
	int index = adder_of_binary_numbers(str1, str2,length_1 - 1,ind -1);
	index--;
	for (; index >= 0; index--)
		printf("%c", result[index]);
	_getch();
}

int adder_of_binary_numbers(char* str1, char* str2, int length_1, int length_2){
	char carry = '0';
	int index = 0;
	while (length_1 >= 0 && length_2 >= 0){
		carry = add_binary_digits(str1[length_1], str2[length_2], carry,index);
		length_1 -= 1;
		length_2 -= 1;
		index += 1;
	}
	if (length_1 >= 0){
		for (; length_1 >= 0; length_1--,index++)
			carry = add_binary_digits(str1[length_1], '0', carry,index);
	}
	else if (length_2 >= 0){
		for (; length_2 >= 0; length_2--, index++)
			carry = add_binary_digits(str2[length_1], '0', carry,index);
	}
	if (carry == '1')
		result[index++] = '1';
	result[index] = '\0';
	return index;
}

char add_binary_digits(char num1, char num2, char carry, int index){
	if (num1 == '1' && num2 == '1'){
		if (carry == '1')
			result[index++] = '1';
		else
			result[index++] = '0';
		return '1';
	}
	if ((num1 == '1' && num2 == '0') || (num1 == '0' && num2 == '1')){
		if (carry == '1'){
			result[index++] = '0';
			return '1';
		}
		else{
			result[index++] = '1';
			return '0';
		}
	}
	if (num1 == '0' && num2 == '0'){
		if (carry == '1')
			result[index++] = '1';
		else
			result[index++] = '0';
		return'0';
	}
}