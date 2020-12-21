/*15.given an unsorted array, find out two numbers whose sum is minimal among all 2-tuples in the array*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int find_minimal_sum(int*, int);

void main(){
	int* given_array, number_of_elements, element;
	printf("Enter the number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int) * (number_of_elements + 1));
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	printf("The minimal sum in this array is : %d",find_minimal_sum(given_array, number_of_elements));
	_getch();
}

int find_minimal_sum(int* given_array, int number_of_elements){
	int min1, min2;
	if (given_array[0] > given_array[1]){
		min1 = given_array[1];
		min2 = given_array[0];
	}
	else{
		min1 = given_array[0];
		min2 = given_array[1];
	}
	for (int index = 2; index < number_of_elements; index++){
		if (given_array[index] <= min1){
			min2 = min1;
			min1 = given_array[index];
		}
		else{
			if (given_array[index] <= min2)
				min2 = given_array[index];
		}
	}
	return min1 + min2;
}