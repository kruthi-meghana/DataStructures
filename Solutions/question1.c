/*1.Rotate a given  array given number of times */

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


void rotateArray(int*,int,int);
int* reverseArray(int*, int, int);

void main(){
	int* sample;
	int *result;
	int numberOfRotations;
	int numberOfElements;
	printf("Enter your count of numbers :");
	scanf("%d", &numberOfElements);

	sample = (int*)malloc(sizeof(int) * numberOfElements);
	result = (int*)malloc(sizeof(int) * numberOfElements);

	printf("Enter your numbers : ");
	for (int index = 0; index < numberOfElements; index++)
		scanf("%d", &sample[index]);
		
	printf("Enter your number of rotations : ");
	scanf("%d", &numberOfRotations);

	rotateArray(sample, numberOfRotations, numberOfElements);
	
	for (int i = 0; i < numberOfElements; i++)
		printf("%d", sample[i]);
	_getch();
}

void rotateArray(int *sample, int numberOfRotations, int numberOfElements){
	sample = reverseArray(sample, numberOfElements - numberOfRotations, numberOfElements-1);
	sample = reverseArray(sample, 0, numberOfElements - numberOfRotations - 1);
	sample = reverseArray(sample, 0, numberOfElements - 1);
}

int* reverseArray(int* sample, int firstIndex, int lastIndex){
	for (; firstIndex < lastIndex; firstIndex++, lastIndex--){
		int swap = sample[firstIndex];
		sample[firstIndex] = sample[lastIndex];
		sample[lastIndex] = swap;
	}
	return sample;
}