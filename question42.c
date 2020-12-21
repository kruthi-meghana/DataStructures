/*42.Given an unsorted integer array of length N, find the maximum chain of -ve numbers in the array.
example: input: 1 -2 -3 6 -4 -2 -1 14 2 14 output is 3 */

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int get_max_length_chain(int*, int);

void main(){
	int* given_array, number_of_elements;
	printf("Enter number of elements in array : ");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	printf("%d is the maximun length of -ve chain in given array", get_max_length_chain(given_array, number_of_elements));
	_getch();
}

int get_max_length_chain(int *given_array, int number_of_elements){
	int max_count = -1, count = 0;
	for (int index = 0; index < number_of_elements; index++){
		if (given_array[index] >= 0){
			if (max_count < count)
				max_count = count;
			count = 0;
		}
		else
			count += 1;
	}
	return max_count;
}