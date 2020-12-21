/*6.Given 3 co-ordinates, write a function to find out the type of triangle*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void type_of_triangle(float*);
double calculate_side(float, float, float, float);

void main(){
	float* given_array = (float*)malloc(sizeof(float)*6);
	printf("enter the co-ordinates");
	for (int index = 0; index < 6; index++)
		scanf("%f", &given_array[index]);
	type_of_triangle(given_array);
	_getch();
}

void type_of_triangle(float* given_array){
	double side1 = calculate_side(given_array[0], given_array[1], given_array[2], given_array[3]);
	double side2 = calculate_side(given_array[0], given_array[1], given_array[4], given_array[5]);
	double side3 = calculate_side(given_array[2], given_array[3], given_array[4], given_array[5]);
	double square_roort_side1 = sqrt(side1);
	double square_roort_side2 = sqrt(side2);
	double square_roort_side3 = sqrt(side3);
	if (square_roort_side1 > square_roort_side2 + square_roort_side3 || square_roort_side2 > square_roort_side1 + square_roort_side3 || square_roort_side3 > square_roort_side1 + square_roort_side2)
		printf("Sorry the given co ordinates cannot form a triangle");
	else{
		if (side1 == side2 + side3 || side2 == side1 + side3 || side3 == side1 + side2){
			if (square_roort_side1 == square_roort_side2 || square_roort_side2 == square_roort_side1 || square_roort_side3 == square_roort_side2)
				printf("The given triangle is right angled isoceles triangle");
			else
				printf("The given triangle is right angled");
		}
		else if (square_roort_side1 == square_roort_side2 == square_roort_side3){
			printf("The given triangle is equilateral");
		}
		else if (square_roort_side1 == square_roort_side2 || square_roort_side1 == square_roort_side3 || square_roort_side2 == square_roort_side3){
			printf("The given triangle is isocelese");
		}
		else{
			printf("The given triangle is scalene");
		}
	}

}

double calculate_side(float c1, float c2, float c3, float c4){
	double sol = pow((c1 - c2), 2) + pow((c3 - c4), 2);
	return sol;
}