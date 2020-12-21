/*55.Print all binary numbers from 1 to n */

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
void get_binary_value(int);
void main(){
	int number;
	printf("Enter a n value");
	scanf("%d", &number);
	for (int num = 1; num <= number; num++)
		get_binary_value(num);
	_getch();
}

void get_binary_value(int number){
	int* binary_value = (int*)malloc(sizeof(int) * 20);
	int index = 0;
	while (number > 0){
		binary_value[index++] = number % 2;
		number /= 2;
	}
	for (int ind = index - 1; ind >= 0; ind--)
		printf("%d", binary_value[ind]);
	printf("\n");
}