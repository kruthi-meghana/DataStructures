/*5.given a number find out whether the number is divisible by 11 or not*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isDivisible_by_11(int);

void main(){
	int given_number;
	printf("Enter your number :");
	scanf("%d", &given_number);
	if (isDivisible_by_11(given_number))
		printf("Given number %d is divisible by 11", given_number);
	else
		printf("Given number %d is not divisible by 11", given_number);
	_getch();
}

bool isDivisible_by_11(int given_number){
	int sum_of_odd = 0, sum_of_even = 0,count = 0;
	while (given_number){
		if (count == 0){
			sum_of_odd += given_number % 10;
			count = 1;
		}
		else{
			sum_of_even += given_number % 10;
			count = 0;
		}
		given_number /= 10;
	}
	if ((sum_of_odd - sum_of_even) == 0 || abs(sum_of_odd - sum_of_even) == 11)
		return true;
	return false;
}