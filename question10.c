/* 10.write a function to print a date in english*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void english_format(char*);
void print_date(char,char);
void print_month(int);

void main(){
	char* given_date, ch;
	int index;
	given_date = (char*)malloc(sizeof(char) * 11);
	printf("Enter your date in dd-mm-yyyy format : ");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		given_date[index] = ch;
	given_date[index] = '\0';
	english_format(given_date);
	_getch();
}

void english_format(char* given_date){
	int day = (given_date[0] - '0') * 10 + (given_date[1] - '0');
	int month = (given_date[3] - '0') * 10 + (given_date[4] - '0');
	if (0 < day < 32 && 0 < month < 13){
		print_date(given_date[0], given_date[1]);
		print_month(month);
		printf(",%c%c%c%c", given_date[6], given_date[7], given_date[8], given_date[9]);
	}
	else{
		printf("Invalid Date");
	}
	
}

void print_date(char first, char second){
	switch (second){
	case '1': 
		if (first == '1'){
			printf("11th");
			return;
		}
		printf("%c%cst", first, second);
		break;
	case '2': printf("%c%cnd", first, second);
		break;
	case '3': printf("%c%crd", first, second);
		break;
	case '4': printf("%c%cth", first, second);
		break;
	case  '5': printf("%c%cth", first, second);
		break;
	case '6': printf("%c%cth", first, second);
		break;
	case '7': printf("%c%cth", first, second);
		break;
	case  '8': printf("%c%cth", first, second);
		break;
	case '9':printf("%c%cth", first, second);
		break;
	case '0': printf("%c%cth", first, second);
		break;
	}
}

void print_month(int month){
	switch (month){
	case 1: printf(" January");
		break;
	case 2:printf(" February");
		break;
	case 3: printf(" March");
		break;
	case 4:printf(" April");
		break;
	case 5: printf(" May");
		break;
	case 6:printf(" June");
		break;
	case 7: printf(" July");
		break;
	case 8:printf(" August");
		break;
	case 9: printf(" September");
		break;
	case 10:printf(" october");
		break;
	case 11: printf(" November");
		break;
	case 12:printf(" December");
		break;
	}
}