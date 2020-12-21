/*59.Print all possible subsets of n numbers.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

void get_r_size_subset(int arr[], int *data, int start, int end, int index, int r);
void print_all_possible_combinations(int arr[], int n);

int main()
{
	int* given_array, number_of_elements;
	printf("Enter number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter your elements");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);

	print_all_possible_combinations(given_array, number_of_elements);
	_getch();
}

void print_all_possible_combinations(int given_array[], int n){
	int* r_size_subsets;
	for (int count = 1; count <= n; count++){
		r_size_subsets = (int*)malloc(sizeof(int)*count);
		get_r_size_subset(given_array, r_size_subsets, 0, n - 1, 0, count);
		free(r_size_subsets);
	}

}

void get_r_size_subset(int* given_array, int* r_size_subsets, int start, int end, int index, int r_size){
	if (index == r_size){
		for (int j = 0; j< r_size; j++)
			printf("%d ", r_size_subsets[j]);
		printf("\n");
		return;
	}
	for (int i = start; i <= end && end - i + 1 >= r_size - index; i++){
		r_size_subsets[index] = given_array[i];
		get_r_size_subset(given_array, r_size_subsets, i + 1, end, index + 1, r_size);
	}
}
