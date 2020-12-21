/*12.given a sorted array, insert a given number into the array at appropriate position*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

void insert_element_in_sorted_array(int*, int, int);
int get_index_binary_search(int*, int, int);

void main(){
	int* given_array, number_of_elements;
	printf("Enter the number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int) * (number_of_elements + 1));
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	int element;
	printf("Enter your Number:");
	scanf("%d", &element);
	insert_element_in_sorted_array(given_array, number_of_elements, element);
	for (int index = 0; index < number_of_elements + 1; index++)
		printf("%d \n", given_array[index]);
	_getch();
}

void insert_element_in_sorted_array(int* given_array, int number_of_element, int element){
	int index = get_index_binary_search(given_array, number_of_element, element);
	int index_element = given_array[index];
	given_array[index] = element;
	for (int ind = index + 1; ind < number_of_element+1; ind++){
		int swap = given_array[ind];
		given_array[ind] = index_element;
		index_element = swap;
	}
}

int get_index_binary_search(int* given_array, int number_of_element, int element){
	int low = 0, high = number_of_element - 1;
	while (low < high){
		int mid = (low + high) / 2;
		if (given_array[mid] > element){
			if (given_array[mid - 1] < element)
				return mid;
			low = mid + 1;
		}else{
			if (given_array[mid + 1] > element)
				return mid + 1;
			high = mid - 1;
		}
	}
	return low;
}