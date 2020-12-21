/*41.Given an array of size N, and two index inputs I and J, remove all elements from I to J (both inclusive) in the array. return the same array to main*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void remove_numbers(int*, int, int, int);

void main(){
	int* given_array, number_of_elements;
	printf("Enter number of elements in array : ");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	int index1, index2;
	printf("Enter your indices :");
	scanf("%d", &index1);
	scanf("%d", &index2);

	remove_numbers(given_array, index1, index2+1, number_of_elements);
	for (int index = 0; index < number_of_elements - ((index2-index1)+1); index++)
		printf("%d \n", given_array[index]);
	_getch();
}

void remove_numbers(int* given_array, int index1, int index2, int number_of_elements){
	for (; index2 < number_of_elements;){
		given_array[index1++] = given_array[index2++];
	}
	given_array[index1] = NULL;
}