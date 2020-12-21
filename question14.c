/*14.given an unsorted array and a number, find out how many elements are bigger than the number and how many are less than that number*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int get_max_count(int*, int, int);

void main(){
	int* given_array, number_of_elements,element;
	printf("Enter the number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int) * (number_of_elements + 1));
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	printf("Enter your number :");
	scanf("%d", &element);
	int count_of_greater_numbers = get_max_count(given_array, number_of_elements, element);
	printf("%d is the count of numbers greater than %d\n%d is the count of numbers less than %d",count_of_greater_numbers,element,number_of_elements-count_of_greater_numbers,element);
	_getch();
}

int get_max_count(int* given_array, int number_of_elements, int element){
	int count_of_greater_numbers = 0;
	for (int index = 0; index < number_of_elements; index++){
		if (given_array[index] > element)
			count_of_greater_numbers += 1;
	}
	return count_of_greater_numbers;
}