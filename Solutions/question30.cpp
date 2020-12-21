/*30.given a numbr as input, convert to string.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char* convert_into_string(int );
int power(int);
int get_number(int);
void main(){
	int number;
	printf("Enter your number :");
	scanf("%d", &number);
	char* number_in_str = convert_into_string(number);
	printf("your string : %s", number_in_str);
	_getch();
}

char* convert_into_string(int number){
	char * str;
	int number_of_digits = get_number(number), index = 0;
	str = (char*)malloc(sizeof(char)*number_of_digits);

	while (number > 0){
		int value = power(number_of_digits - 1);
		str[index++] = number /value + '0';
		number_of_digits--;
		number = number % value;
	}
	str[index] = '\0';
	return str;
}
int power(int number_of_digits ){
	int number = 1;
	for (; number_of_digits > 0;number_of_digits--)
		number *= 10;
	return number;
}
int get_number(int number){
	int count = 0;
	while (number > 0){
		number /= 10;
		count++;
	}
	return count;
}