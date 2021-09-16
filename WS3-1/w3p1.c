/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   :Deyang Xie
	ID     :150162204
	Email  :dxie17@myseneca.ca
	Section:NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main()
{
	int const JAN = 1, DEC = 12;
	int year, month;


	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);


		if (year < MIN_YEAR || year> MAX_YEAR)
		{
			printf("ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
		if (month < JAN || month> DEC)
		{
			printf("ERROR: Jan.(1) - Dec.(12)\n");
		}

	} while (year < MIN_YEAR || year > MAX_YEAR || month < JAN || month > DEC);

	printf("\n");
	printf("*** Log date set! ***\n");
	printf("\n");

	switch (month)
	{
	case 1:
		printf("Log starting date: %d-JAN-01", year);
		break;
	case 2:
		printf("Log starting date: %d-FEB-01", year);
		break;
	case 3:
		printf("Log starting date: %d-MAR-01", year);
		break;
	case 4:
		printf("Log starting date: %d-APR-01", year);
		break;
	case 5:
		printf("Log starting date: %d-MAY-01", year);
		break;
	case 6:
		printf("Log starting date: %d-JUN-01", year);
		break;
	case 7:
		printf("Log starting date: %d-JUL-01", year);
		break;
	case 8:
		printf("Log starting date: %d-AUG-01", year);
		break;
	case 9:
		printf("Log starting date: %d-SEP-01", year);
		break;
	case 10:
		printf("Log starting date: %d-OCT-01", year);
		break;
	case 11:
		printf("Log starting date: %d-NOV-01", year);
		break;
	case 12:
		printf("Log starting date: %d-DEC-01", year);
		break;
	}
	return 0;
}