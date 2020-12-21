/*8.write a function which takes an array as input and finds out the two largest values of the array*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void two_largest_elements_of_array(int*, int);

void main(){
	int *given_array, number_of_elements ;
	printf("Enter the number of elements in array :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int) * number_of_elements);
	printf("Enter you elements :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	two_largest_elements_of_array(given_array, number_of_elements);
	_getch();
}

void two_largest_elements_of_array(int* given_array, int number_of_elements){
	int largest_one, largest_two;
	if (given_array[0] > given_array[1]){
		largest_one = given_array[0];
		largest_two = given_array[1];
	}
	else{
		largest_one = given_array[1];
		largest_two = given_array[2];
	}
	for (int index = 2; index < number_of_elements; index++){
		if (largest_one < given_array[index]){
			largest_one = given_array[index];
			largest_two = largest_one;
		}else{
			if (largest_two < given_array[index])
				largest_two = given_array[index];
		}
	}
	printf("The first largest number is : %d \nThe second largest number is : %d", largest_one, largest_two);
}