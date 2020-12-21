/*29.given two sorted arrays, one ascending and one descending, create a third array which is sorted in ascending*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int get_sorted_in_ascending(int*, int*, int*, int, int);

void main(){
	int* sorted_ascending, *sorted_descending, *third_sorted;
	int number_of_elements_1, number_of_elements_2;

	printf("Enter number of elements in first array : ");
	scanf("%d", &number_of_elements_1);

	sorted_ascending = (int*)malloc(sizeof(int)*number_of_elements_1);
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements_1; index++)
		scanf("%d", &sorted_ascending[index]);

	printf("Enter number of elements in second array :");
	scanf("%d", &number_of_elements_2);
	sorted_descending = (int*)malloc(sizeof(int)*number_of_elements_2);
	printf("Enter your elements:");
	for (int index = 0; index < number_of_elements_2; index++)
		scanf("%d", &sorted_descending[index]);
	third_sorted = (int*)malloc(sizeof(int)*(number_of_elements_2 + number_of_elements_1));
	int number_of_elements = get_sorted_in_ascending(sorted_ascending, sorted_descending, third_sorted, number_of_elements_1, number_of_elements_2);
	printf("The final sorted array : \n");
	for (int index = 0; index < number_of_elements; index++)
		printf("%d \n", third_sorted[index]);

	_getch();
}

int get_sorted_in_ascending(int* sorted_ascending, int* sorted_descending, int * third_sorted, int number_of_elements_1, int number_of_elements_2){
	
	int number_of_elements = 0, number = sorted_descending[number_of_elements_2 - 1], index_of_second_array = number_of_elements_2 - 2;
	
	for (int index = 0; index < number_of_elements_1 || index_of_second_array >= 0;){
		if (index < number_of_elements_1 && index_of_second_array >= 0){
			if (sorted_ascending[index] < number)
				third_sorted[number_of_elements++] = sorted_ascending[index++];
			else{
				third_sorted[number_of_elements++] = number;
				number = sorted_descending[index_of_second_array--];
			}
		}
		else if (index >= number_of_elements_1){
			third_sorted[number_of_elements++] = number;
			number = sorted_descending[index_of_second_array--];
		}
		else if (index_of_second_array < 0){
			third_sorted[number_of_elements++] = sorted_ascending[index++];
		}
	}
	if (number_of_elements < number_of_elements_1 + number_of_elements_2)
		third_sorted[number_of_elements++] = number;
	return number_of_elements;
}