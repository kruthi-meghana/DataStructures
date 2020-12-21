/*3.Convert a decimal number to hexa-Decimal number*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char* decimal_to_hexaDecimal(int);

int index = 0;

void main(){
	int decimal_number;
	char* hexaDecimal_number;
	hexaDecimal_number = (char*)malloc(sizeof(char) * 100);
	
	printf("Enter your decimal number:");
	scanf("%d", &decimal_number);
	hexaDecimal_number = decimal_to_hexaDecimal(decimal_number);
	
		
	_getch();
}

char* decimal_to_hexaDecimal(int decimal_number){
	char hexaDecimal_number[100];
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

