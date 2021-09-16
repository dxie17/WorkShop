/*
	==================================================
	Workshop #3 (Part-2):
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
#define LOG_DAYS 3

void printfdate(year, month, day)
//create a fuction to print date as 0000-JAN-01
{
	switch (month)
	{
	case 1:
		printf("\n%04d-JAN-%02d\n", year, day);
		break;
	case 2:
		printf("\n%04d-FEB-%02d\n", year, day);
		break;
	case 3:
		printf("\n%04d-MAR-%02d\n", year, day);
		break;
	case 4:
		printf("\n%04d-APR-%02d\n", year, day);
		break;
	case 5:
		printf("\n%04d-MAY-%02d\n", year, day);
		break;
	case 6:
		printf("\n%04d-JUN-%02d\n", year, day);
		break;
	case 7:
		printf("\n%04d-JUL-%02d\n", year, day);
		break;
	case 8:
		printf("\n%04d-AUG-%02d\n", year, day);
		break;
	case 9:
		printf("\n%04d-SEP-%02d\n", year, day);
		break;
	case 10:
		printf("\n%04d-OCT-%02d\n", year, day);
		break;
	case 11:
		printf("\n%04d-NOV-%02d\n", year, day);
		break;
	case 12:
		printf("\n%04d-DEC-%02d\n", year, day);
		break;
	}
}



int main()
{
	int const JAN = 1, DEC = 12;
	int i, year = 0, month = 0, day = 1;
	float morrating = 0, evenrating = 0, summor = 0, sumeven = 0;
	printf("General Well-being Log\n");
	printf("======================\n");

	printf("Set the year and month for the well-being log (YYYY MM): ");
	scanf("%d %d", &year, &month);

	while (year < MIN_YEAR || year > MAX_YEAR || month < JAN || month > DEC)
	{

		if (year < MIN_YEAR || year> MAX_YEAR)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}
		if (month < JAN || month> DEC)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}

		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

	}

	printf("\n*** Log date set! ***\n");

	for (i = 1; i <= LOG_DAYS; i++)
	{
		printfdate(year, month, day);
		day++;

		printf("   Morning rating (0.0-5.0): ");
		scanf("%f", &morrating);
		while (morrating < 0 || morrating > 5.0)
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			printf("   Morning rating (0.0-5.0): ");
			scanf("%f", &morrating);
		}
		summor += morrating;


		printf("   Evening rating (0.0-5.0): ");
		scanf("%f", &evenrating);
		while (evenrating < 0.0 || evenrating>5.0)
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			printf("   Evening rating (0.0-5.0): ");
			scanf("%f", &evenrating);
		}
		sumeven += evenrating;

	}

	printf("\nSummary\n");
	printf("=======\n");

	printf("Morning total rating: %.3f\n", summor);
	printf("Evening total rating: %.3f\n", sumeven);
	printf("----------------------------\n");
	printf("Overall total rating: %.3f\n", (sumeven + summor));
	printf("\nAverage morning rating:  %.1f\n", summor / LOG_DAYS);
	printf("Average evening rating:  %.1f\n", sumeven / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1f\n", (sumeven + summor) / LOG_DAYS / 2);
	return 0;
}
