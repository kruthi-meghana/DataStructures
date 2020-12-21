/*21.Median of 2 sorted arrays*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int get_max(int number1, int number2);
int get_min(int number1, int number2);

void main(){
	int *given_array_1, number_of_elements, number_of_elements2, *given_array_2;

	printf("Enter number of elements in first array:");
	scanf("%d", &number_of_elements);
	given_array_1 = (int*)malloc(sizeof(int)*number_of_elements);

	printf("Enter the elements of first array :");
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array_1[index]);

	printf("Enter number of elements in second array:");
	scanf("%d", &number_of_elements2);
	given_array_2 = (int*)malloc(sizeof(int)*number_of_elements2);

	printf("Enter the elements of second array :");
	for (int index = 0; index < number_of_elements2; index++)
		scanf("%d", &given_array_2[index]);

	printf("Median of given arrays is : %d", median_of_two_sorted_arrays(given_array_1,0, number_of_elements - 1, given_array_2, 0, number_of_elements2 - 1));
	_getch();
}

int median_of_two_sorted_arrays(int* given_array_1, int low1, int high1, int* given_array_2, int low2, int high2){
	if (low1 - high1 == 1 && low2 - high2 == 1)
		return (get_max(given_array_1[low1] , given_array_2[low1]) + get_min(given_array_1[high1] , given_array_2[high2])) / 2;
	
	int median1 = median(given_array_1, (high1 - low1) + 1);
	int median2 = median(given_array_2, (high2 - low2) + 1);

	if (median1 == median2)
		return median1;
	if (median1 < median2){
		if (((high1 - low1) + 1) % 2 == 0){

		}
	}

}

int median(int* given, int length){
	if (length % 2 == 0)
		return (given[length / 2] + given[(length - 1) / 2]) / 2;
	return given[length / 2];
}
int get_min(int number1, int number2){
	if (number1 < number2)
		return number1;
	return number2;
}

int get_max(int number1, int number2){
	if (number1 > number2)
		return number1;
	return number2;
}