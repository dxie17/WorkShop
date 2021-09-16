/*
	==================================================
	Workshop #4 (Part-2):
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
	int wish, years, priority, months, i = 0, wishlist = 3, months_cal;
	int flag_finance[3] = { 0 }, portant[wish_MAX] = { 0 };
	double income, sum_income = 0;
	double wishcost[wish_MAX] = { 0 }, totalportant[3] = { 0 };
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

	for (i = 0; i < wish; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		printf("   Item cost: $");
		scanf("%lf", &wishcost[i]);
		while (wishcost[i] < wishcost_MIN)
		{
			printf("      ERROR: Cost must be at least $%.2lf\n", wishcost_MIN);
			printf("   Item cost: $");
			scanf("%lf", &wishcost[i]);
		}

		printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
		scanf("%d", &portant[i]);
		while ((portant[i] != 1) && (portant[i] != 2) && (portant[i] != 3))
		{
			printf("      ERROR: Value must be between 1 and 3\n");
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &portant[i]);
		}

		printf("   Does this item have financing options? [y/n]: ");
		scanf(" %c", &finance[i]);
		while ((finance[i] != 'y') && (finance[i] != 'n'))
		{
			printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);
		}
	}


	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < wish; i++)
	{
		printf("  %d      %d        %c     %10.2lf\n", i + 1, portant[i], finance[i], wishcost[i]);
		sum_income += wishcost[i];

		if (portant[i] == 1)
		{
			totalportant[0] += wishcost[i];
			if (finance[i] == 'y')
			{
				flag_finance[0] += 1;
			}
		}
		else if (portant[i] == 2)
		{
			totalportant[1] += wishcost[i];

			if (finance[i] == 'y')
			{
				flag_finance[1] += 1;
			}
		}
		else if (portant[i] == 3)
		{
			totalportant[2] += wishcost[i];
			if (finance[i] == 'y')
			{
				flag_finance[2] += 1;
			}
		}
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $ %10.2lf\n", sum_income);


	while (wishlist)
	{
		printf("\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &wishlist);
		if ((wishlist != 1) && (wishlist != 2) && (wishlist != 0))
		{
			printf("\nERROR: Invalid menu selection.\n");
		}

		else if (wishlist == 1)
		{
			printf("\n\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", sum_income);

			years = (int)(sum_income / income) / 12;
			months_cal = ((int)(sum_income * 100)) % ((int)(income * 100));

			if (months_cal == 0)
			{
				months = (int)(sum_income / income) - 12 * years;
			}
			else if (months_cal > 0)
			{
				months = (int)(sum_income / income) - 12 * years + 1;
			}


			printf("Forecast: %d years, %d months \n", years, months);
			if ((flag_finance[0] + flag_finance[1] + flag_finance[2]) > 0)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}

		else if (wishlist == 2)
		{
			printf("\n\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &priority);
			while ((priority != 1) && (priority != 2) && (priority != 3))
			{
				printf("ERROR: Value must be between 1 and 3\n");
				printf("\nWhat priority do you want to filter by? [1-3]: \n");
				scanf("%d", &priority);
			}

			printf("\n====================================================\n");
			printf("Filter:   by priority(%d)\n", priority);
			printf("Amount:   $%.2lf\n", totalportant[priority - 1]);

			years = (int)(totalportant[priority - 1]) / income / 12;
			months_cal = ((int)(totalportant[priority - 1] * 100)) % ((int)(income * 100));
			//make the calculation and converting from double to int more accrate.

			if (months_cal == 0)
			{
				months = (int)(totalportant[priority - 1] / income) - 12 * years;
			}

			else if (months_cal > 0)
			{
				months = (int)(totalportant[priority - 1] / income) - 12 * years + 1;
			}

			printf("Forecast: %d years, %d months \n", years, months);

			if (flag_finance[priority - 1] > 0)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}
	}

	printf("\nBest of luck in all your future endeavours!");
	return 0;
}
