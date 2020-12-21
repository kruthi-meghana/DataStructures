/*57.Given an array where every element occurs three times, except one element which occurs only once. 
Find the element that occurs once.ex: arr=12, 1, 12, 3, 12, 1, 1, 2, 3, 3
o/p: 2*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

void main(){
	int* given_array, number_of_elements;
	printf("Enter number of elements :");
	scanf("%d", &number_of_elements);

	given_array = (int*)malloc(sizeof(int)*number_of_elements);

	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);

	printf("%d is the number", get_single_occured_element(given_array, number_of_elements));
	_getch();
}

int get_single_occured_element(int* given_array, int number_of_elements){
	sort_array(given_array, number_of_elements);
	for (int index = 0; index < number_of_elements - 3; index++){
		if (given_array[index] != given_array[index + 1])
			return given_array[index];
		if (given_array[index] == given_array[index + 1])
			index += 3;
	}
}

void sort_array(int* given_array, int number_of_elements){
}