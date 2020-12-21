/*56. Count the set bits of a number in binary format.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
int get_set_bit_value(int);
void main(){
	int number;
	printf("Enter a n value");
	scanf("%d", &number);
	printf("%d : is the number of set bits in %d", get_set_bit_value(number), number);
	_getch();
}

int get_set_bit_value(int number){
	int count_of_set_bits = 0;
	while (number > 0){
		if(number % 2 == 1)
			count_of_set_bits++;
		number /= 2;
	}
	return count_of_set_bits;
}