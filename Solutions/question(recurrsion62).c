/*62.Factorial of a given number
This problem was actually given to us to know about stack frame and it's size by infinty recurrsion i.e no base condition.
*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int factorial_of(int);
void main(){
	int given_number;
	printf("Enter your number");
	scanf("%d", &given_number);
	printf("%d",factorial_of(given_number));
	_getch();
}

int factorial_of(int given_number){
	if (given_number == 1)
		return 1;
	return given_number * factorial_of(given_number - 1);
}