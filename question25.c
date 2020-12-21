/*25.given an array that has duplicate values remove all duplicate values input*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int remove_duplicate(int*, int ,int*);
void main(){
	int *given_array, number_of_elements;
	printf("Enter the number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter the elements in to the array");
	
	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	int* change_array = (int*)malloc(sizeof(int)*number_of_elements);
	int index2 = 0;
	index2 = remove_duplicate(given_array, number_of_elements, change_array);
	for (int index = 0; index < index2; index++)
		printf("%d \n", change_array[index]);
	_getch();
}

int remove_duplicate(int* given_array, int number_of_elements, int* change_array){
	int index2 = 0;
	int flag = 1;
	for (int index = 0; index < number_of_elements; index++){
		flag = 1;
		for (int j = 0; j < index2; j++){
			if (change_array[j] == given_array[index]){
				flag = 0;
				break;
			}
		}
		if (flag != 0){
			change_array[index2++] = given_array[index];
		}
	}
	return index2;
}