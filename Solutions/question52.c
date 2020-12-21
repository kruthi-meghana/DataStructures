/*52.given an unsorted array, find out the continuous triplet (3-set) whose sum is maximum in the array.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

void main(){
	int* given_unsorted_array, number_of_elements;
	printf("Enter number of elements in unsorted array : ");
	scanf("%d", &number_of_elements);
	given_unsorted_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter your elements in to unsorted array :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_unsorted_array[index]);
	printf("and their sum is : %d", get_max_sum(given_unsorted_array, number_of_elements));
	_getch();
}

int get_max_sum(int* given_unsorted_array, int number_of_elements){
	int max_sum = given_unsorted_array[0] + given_unsorted_array[1] + given_unsorted_array[2], sum = 0;
	int num1 = given_unsorted_array[0], num2 = given_unsorted_array[1], num3 = given_unsorted_array[2];
	for (int index = 1; index < number_of_elements - 3; index++){
		sum = given_unsorted_array[index] + given_unsorted_array[index + 1] + given_unsorted_array[index + 2];
		if (sum > max_sum){
			max_sum = sum;
			num1 = given_unsorted_array[index];
			num2 = given_unsorted_array[index + 1];
			num3 = given_unsorted_array[index + 2];
		}
	}
	printf("The continuos triplet:\n%d\n%d\n%d\n", num1, num2, num3);
	return sum;
}