/*27.given two sorted arrays, return a third array which as common elements of both arrays*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

int common_elements(int*, int*, int, int);
bool binarySearch(int*, int , int );
int* third_array;


void main(){
	int* given_array_1, *given_array_2, number_of_elements_1, number_of_elements_2;
	printf("Enter number of elements in first array :");
	scanf("%d", &number_of_elements_1);

	given_array_1 = (int*)malloc(sizeof(int)*number_of_elements_1);
	printf("Enter first array elements:");
	for (int index = 0; index < number_of_elements_1; index++)
		scanf("%d", &given_array_1[index]);
	printf("Enter number of elements in second array :");
	scanf("%d", &number_of_elements_2);

	given_array_2 = (int*)malloc(sizeof(int)*number_of_elements_2);
	printf("Enter second array elements:");
	for (int index = 0; index < number_of_elements_2; index++)
		scanf("%d", &given_array_2[index]);

	int number_of_elements = common_elements(given_array_1, given_array_2, number_of_elements_1, number_of_elements_2);
	for (int index = 0; index < number_of_elements; index++)
		printf("%d \n", third_array[index]);
	_getch();
}

int common_elements(int* given_array_1, int* given_array_2, int number_of_elements_1, int number_of_elements_2){
	third_array = (int*)malloc(sizeof(char) * 50);
	int number_of_elements = 0;
	int index = 0;
	for (int i = 0; i < number_of_elements_1; i++){
		if (binarySearch(given_array_2, number_of_elements_2, given_array_1[i]))
			third_array[number_of_elements++] = given_array_1[i] ;
	}	
	return number_of_elements;
}

bool binarySearch(int* array1, int number_of_elements, int search_element){
	int low = 0;
	int high = number_of_elements - 1;
	while (low <= high){
		int mid = (low + high) / 2;
		if (array1[mid] == search_element)
			return true;
		if (array1[mid] > search_element)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return false;
}