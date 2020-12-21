/*49.Print all +ve numbers starting from 1 in increments of the last two number s sum you got in the sequence.
the sequence starts with 1,1. 1,1,3, 7, 17, 41.....
(41=(2*17)+7,17=(2*7)+3)) print till 1000 numbers(we have to print totally 1000 numbers not till 1000 number)*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void generate_sequence(int, int);
void main(){
	char* number_1 = (char*)malloc(sizeof(char) * 25);
	char* number_2 = (char*)malloc(sizeof(char) * 25);
	generate_sequence(1, 1);
	_getch();
}
char* add(char* number_1, char* number_2, int length_1,int length_2){
	char carry;
	while (length_1)
}
void generate_sequence(int number_1, int number_2){
	int count = 0;
	while (count < 100){
		int next_number = (number_2 * 2) + number_1;
		printf("%d \n", next_number);
		number_1 = number_2;
		number_2 = next_number;
		count += 1;
	}
}