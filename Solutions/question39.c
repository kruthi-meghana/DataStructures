/*39.Given an integer array of size N, which has only values 0's and 1's. sort the array. For this program also write the main for scanf/printf and actual logic in function*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
	int number_of_elements, *binary_array;

	printf("Enter number of elements in first array : ");
	scanf("%d", &number_of_elements);

	binary_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &binary_array[index]);
	int count_of_1 = get_ones_count(binary_array, number_of_elements);
	printf("after sorting :\n");
	for (int index = 0; index < number_of_elements; index++){
		if (index >= number_of_elements-count_of_1)
			printf("1 \n");
		else
			printf("0 \n");
	}
	_getch();
}

int get_ones_count(int* binary_array, int number_of_elements){
	int count = 0;
	for (int index = 0; index < number_of_elements; index++){
		if (binary_array[index] != 0)
			count += 1;
	}
	return count;
}