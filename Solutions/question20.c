/*20.find the count of numbers greater than a given number in a sorted array.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int greatest_numbers_using_binary_search(int*, int, int);

void main(){
	int *given_array, number_of_elements, given_element;
	printf("Enter number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int)*number_of_elements);

	printf("Enter the elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);

	printf("Enter the number:");
	scanf("%d", &given_element);

	printf("%d is the number of greatest elements than %d in given array", greatest_numbers_using_binary_search(given_array, number_of_elements, given_element), given_element);
	_getch();
}

int greatest_numbers_using_binary_search(int* given_array, int number_of_elements, int element){
	int low = 0;
	int high = number_of_elements - 1;
	
	while (low < high){
		int mid = (low + high) / 2;
		if (given_array[mid] > element){
			if (given_array[mid - 1] < element)
				return number_of_elements - mid;
			low = mid + 1;
		}
		else{
			if (given_array[mid + 1] > element)
				return number_of_elements - mid + 1;
			high = mid - 1;
		}
	}
	return number_of_elements- low ;
}