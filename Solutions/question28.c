/*28.given four numbers as input, find the LCM of four numbers*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

void main(){
	int number_1, number_2, number_3, number_4;

	printf("Enter your numbers:");
	scanf("%d", &number_1);
	scanf("%d", &number_2);
	scanf("%d", &number_3);
	scanf("%d", &number_4);


	printf("Lcm of given numbers is : %d",lcm_of_numbers(number_1, number_2, number_3, number_4));
	_getch();
}

int gcd_of_number(int number_1){

}

int lcm_of_numbers(int number_1, int number_2, int number_3, int number_4){
	int lcm = 1,number = 2;
	while (number_1 > 1 || number_2 > 1 || number_3 > 1 || number_4 > 1){
		if (!(number <= number_1 / 2 || number <= number_2 / 2 || number <= number_3 / 2 || number <= number_4 / 2))
			number = 2;
		if (number_1 % number == 0 || number_2 % number == 0 || number_3 % number == 0 || number_4 %number == 0){
			if (number_1 % number == 0)
				number_1 /= number;
			if (number_2 % number == 0)
				number_2 /= number;
			if (number_3 % number == 0)
				number_3 /= number;
			if (number_4 % number == 0)
				number_4 /= number;
			lcm *= number;
			number++;
		}
	}
	return lcm;
}

