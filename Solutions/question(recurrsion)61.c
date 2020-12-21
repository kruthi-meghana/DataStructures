/*61.Fibnocci series upto a given number */

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void generate_fibnocci_series(int, int, int);

void main(){
	int given_number;
	printf("Enter your number");
	scanf("%d", &given_number);
	printf("0 \n1\n");
	generate_fibnocci_series(0, 1, given_number);
	_getch();
}

void generate_fibnocci_series(int number_1,int number_2, int given_number){
	int ans = number_1 + number_2;
	number_1 = number_2;
	number_2 = ans;
	printf("%d \n", number_2);
	if (number_2 >= given_number)
		return;
	generate_fibnocci_series(number_1, number_2, given_number);
	return;
}