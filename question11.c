/*11. write a function which takes a date and finds whether that is a correct date or not*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_31_month(int );
bool isValid_date(char* );

void main(){
	char* given_date, ch;
	int index;
	given_date = (char*)malloc(sizeof(char) * 11);
	printf("Enter your date in dd-mm-yyyy format : ");
	for (index = 0; (ch = getchar()) != '\n'; index++)
		given_date[index] = ch;
	given_date[index] = '\0';
	if (isValid_date(given_date))
		printf("The entered date is valid");
	else
		printf("The entered date is not valid");
	_getch();
}

bool isValid_date(char* given_date){
	int day = (given_date[0] - '0') * 10 + (given_date[1] - '0');
	int month = (given_date[3] - '0') * 10 + (given_date[4] - '0');
	int year = (given_date[6] - '0') * 1000 + (given_date[7] - '0') * 100 + (given_date[8] - '0') * 10 + (given_date[9] - '0');

	if (year % 400 == 0 || year % 4 == 0){
		if (month == 2 && 0 < day && day < 30)
			return true;
	}else{
		if (month == 2 && 0 < day && day < 29)
			return true;
	}
	if (0 < day && day < 31 && !is_31_month(month))
		return true;
	else if (0 < day && day < 32 && is_31_month(month))
		return true;
	return false;
}

bool is_31_month(int month){
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return true;
	return false;
}