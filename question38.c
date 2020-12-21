/*38.Find the array of product of elements in a array, leaving the element a that position.*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int get_product(int*, int, int);

void main(){
	int *given_array, number_of_elements, position;
	printf("Enter the number of elements :");
	scanf("%d", &number_of_elements);
	given_array = (int*)malloc(sizeof(int)*number_of_elements);
	printf("Enter the elements in to the array");

	for (int index = 0; index < number_of_elements; index++)
		scanf("%d", &given_array[index]);
	printf("Enter the position of element which have to be left :");
	scanf("%d", &position);
	printf("%d:is the product", get_product(given_array, position, number_of_elements));
	_getch();
}

int get_product(int* given_array, int position, int number_of_elements){
	int product = 1;
	for (int index = 0; index < number_of_elements; index++){
		if (index != position)
			product *= given_array[index];
	}
	return product;
}