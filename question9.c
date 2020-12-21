/*9.write a function to generate the Nth fibonacci number*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int nth_fibonacci_number(int);

void main(){
	int n;
	printf("Enter your nth :");
	scanf("%d", &n);
	int nth_number = nth_fibonacci_number(n);
	printf("%d : is the %d number in fibonacci number", nth_number, n);
	_getch();
}

int nth_fibonacci_number(int n){
	int first_ele = 0, second_ele = 1, next,count = 2;
	while (count < n){
		next = first_ele + second_ele;
		first_ele = second_ele;
		second_ele = next;
		count += 1;
	}
	return next;
}