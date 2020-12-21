/*40.Given an integer array of size N, write a function to return the Maximum and Minimum values of the array*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int getMax(int*, int);

void main(){
	int* given_array, number_of_elements;
	
	printf("Enter number of elements in first array : ");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter your elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	printf("%d :  is the max value", getMax(given_array, number_of_elements));
	_getch();
}

int getMax(int* given_array, int number_of_elements){
	int max = given_array[0], min = given_array[0];
	for (int index = 0; index < number_of_elements; index++){
		if (max < given_array[index])
			max = given_array[index];
		if (min > given_array[index])
			min = given_array[index];
	}
	printf("%d : is the min value\n", min);
	return max;
}