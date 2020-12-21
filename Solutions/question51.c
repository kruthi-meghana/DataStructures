/*51.given an array which is sorted and another array unsorted, 
find whether both arrays have same elements without sorting the second array*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

void identify_common_elements(int* , int* , int , int );
bool isElementInSortedArray(int* , int , int );

void main(){
	int* given_sorted_array, number_of_elements;
	int* given_unsorted_array, number_of_elements_2;
	printf("Enter number of elements in sorted array : ");
	scanf("%d", &number_of_elements);
	given_sorted_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_sorted_array[index]);

	printf("Enter number of elements in unsorted array : ");
	scanf("%d", &number_of_elements_2);
	given_unsorted_array = (int*)malloc(sizeof(int)*number_of_elements_2);
	printf("Enter your elements in to unsorted array :");
	for (int index = 0; index < number_of_elements_2; index++)
		scanf("%d", &given_unsorted_array[index]);
	printf("\nHere are the numbers in common :");
	identify_common_elements(given_sorted_array, given_unsorted_array, number_of_elements, number_of_elements_2);
	_getch();
}

void identify_common_elements(int* given_sorted_array, int* given_unsorted_array, int number_of_elements, int number_of_elements_2){
	int index = 0;
	for (; index < number_of_elements_2; index++){
		if (isElementInSortedArray(given_sorted_array, number_of_elements, given_unsorted_array[index]))
			printf("%d", given_unsorted_array[index]);
	}
}

bool isElementInSortedArray(int* given_sorted_array, int number_of_elements,int number){
	int low = 0;
	int high = number_of_elements - 1;
	while (low <= high){
		int mid = (low + high) / 2;
		if (given_sorted_array[mid] == number)
			return true;
		else if (given_sorted_array[mid] > number)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return false;
}

