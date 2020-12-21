/*23.given a decimal number, write a function to print the hex value of the number*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* convert_in_to_hexadecimal(int);
int index = 0;

void main(){
	int number;
	printf("Enter your number :");
	scanf("%d", &number);
	char* hexadecimal;
	hexadecimal = (char*)malloc(sizeof(char) * 20);
	hexadecimal = convert_in_to_hexadecimal(number);
	
	_getch();
}

char* convert_in_to_hexadecimal(int decimal_number){
	char hexaDecimal_number[20];
	int power = 0;

	while (decimal_number != 0){
		int digit = decimal_number / 16;
		int hexaDecimal_digit = ((decimal_number)-(16 * digit));
		if (hexaDecimal_digit < 10)
			hexaDecimal_number[index++] = hexaDecimal_digit + 48;
		else{
			switch (hexaDecimal_digit){
			case 10:  hexaDecimal_number[index++] = 'A';
				break;
			case 11:  hexaDecimal_number[index++] = 'B';
				break;
			case 12:  hexaDecimal_number[index++] = 'C';
				break;
			case 13:  hexaDecimal_number[index++] = 'D';
				break;
			case 14:  hexaDecimal_number[index++] = 'E';
				break;
			case 15:  hexaDecimal_number[index++] = 'F';
				break;
			default:  index += 1 - 1;

			}
		}
		decimal_number = digit;
		power += 1;
	}
	hexaDecimal_number[index] = '\0';
	for (int j = index - 1; j >= 0; j--){
		char ch = hexaDecimal_number[j];
		printf("%c", ch);
	}
	return hexaDecimal_number;
}