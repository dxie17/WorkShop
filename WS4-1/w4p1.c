/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   :Deyang Xie
	ID     :150162204
	Email  :dxie17@myseneca.ca
	Section:NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


#define income_MIN 500.00
#define income_MAX 400000.00
#define wish_MAX 10
#define wish_MIN 1
#define wishcost_MIN 100.00


int main()
{
	int wish, i = 1, portant[wish_MAX] = { 0 };
	double income, sum_income = 0, wishcost[wish_MAX] = { 0 };
	char finance[wish_MAX] = { 0 };

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	printf("\nEnter your monthly NET income: $");
	scanf("%lf", &income);

	while (income< income_MIN || income >income_MAX)
	{
		if (income < income_MIN)
		{
			printf("ERROR: You must have a consistent monthly income of at least $%0.2lf\n", income_MIN);
		}
		else if (income > income_MAX)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%0.2lf\n", income_MAX);
		}

		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &income);
	}

	printf("\nHow many wish list items do you want to forecast?: ");
	scanf("%d", &wish);

	while (wish < wish_MIN || wish > wish_MAX)
	{
		printf("ERROR: List is restricted to between %d and %d items.\n", wish_MIN, wish_MAX);
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &wish);
	}

	for (i = 1; i <= wish; i++)
	{
		printf("\nItem-%d Details:\n", i);
		printf("   Item cost: $");
		scanf("%lf", &wishcost[i - 1]);
		while (wishcost[i - 1] < wishcost_MIN)
		{
			printf("      ERROR: Cost must be at least $%.2lf\n", wishcost_MIN);
			printf("   Item cost: $");
			scanf("%lf", &wishcost[i - 1]);
		}

		printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
		scanf("%d", &portant[i - 1]);
		while ((portant[i - 1] != 1) && (portant[i - 1] != 2) && (portant[i - 1] != 3))
		{
			printf("      ERROR: Value must be between 1 and 3\n");
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &portant[i - 1]);
		}

		printf("   Does this item have financing options? [y/n]: ");
		scanf(" %c", &finance[i - 1]);
		while ((finance[i - 1] != 'y') && (finance[i - 1] != 'n'))
		{
			printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i - 1]);
		}
	}


	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 1; i <= wish; i++)
	{
		printf("  %d      %d        %c     %10.2lf\n", i, portant[i - 1], finance[i - 1], wishcost[i - 1]);
		sum_income += wishcost[i - 1];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $ %10.2lf\n", sum_income);
	printf("\nBest of luck in all your future endeavours!\n");
	return 0;
}
