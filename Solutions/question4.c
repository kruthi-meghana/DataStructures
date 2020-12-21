/* 4. given a number write a function to return the sum of all digits to the main program*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int digit_sum(int);

void main(){
	int given_number;
	printf("Enter your number :");
	scanf("%d", &given_number);
	int sum_of_digits = digit_sum(given_number);
	printf("%d", sum_of_digits);
	_getch();
}

int digit_sum(int given_number){
	int sum = 0;
	while (given_number){
		sum += given_number % 10;
		given_number /= 10;
	}
	return sum;
}

