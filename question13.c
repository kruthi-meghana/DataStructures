/*13. In a given sorted array, two numbers are changed their position, please fix those two numbers*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

void fix_sorted_array(int*, int);

void main(){
	int* given_array, number_of_elements;
	printf("Enter the number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int) * number_of_elements);
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);

	fix_sorted_array(given_array, number_of_elements);
	for (int index = 0; index < number_of_elements; index++)
		printf("%d\n", given_array[index]);
	_getch();
}

void fix_sorted_array(int* given_array, int number_of_elements){
	int flag = 0 ,index, index2;
	for (index = number_of_elements - 1; index >= 0; index--){
		if (given_array[index] < given_array[index - 1]){
			index2 = index - 1;
			while (index2 >= 0 && given_array[index] < given_array[index2])
				index2 -= 1;
			break;
		}
	}
	int swap = given_array[index];
	given_array[index] = given_array[index2+1];
	given_array[index2+1] = swap;
}