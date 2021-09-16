/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   :Deyang Xie
	ID     :150162204
	Email  :dxie17@myseneca.ca
	Section:NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	float firstamount, servicefee;
	int amount, remaining, penny, feerate = 5, toonie, loonie, quarter, dime, nickel;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%f", &firstamount);
	amount = (int)(firstamount * 100 + 0.5);//eliminate the memory difference when convert from two decimals which multiplies by 100 to an integer.
	servicefee = (int)(amount * feerate / 100.0 + 0.5) / 100.0;//round up the service fee.
	remaining = amount - servicefee * 100;
	printf("Service fee (%0.1lf percent):%0.2f\n", (float)feerate, servicefee);
	printf("Balance to dispense: $%0.2f\n", (float)remaining / 100.0);
	printf("\n");

	toonie = (remaining - remaining % 200) / 200;
	remaining = remaining - toonie * 200;
	printf("$2.00 Toonies  X %d (remaining: $%0.2f)\n", toonie, (float)remaining / 100.0);

	loonie = (remaining - remaining % 100) / 100;
	remaining = remaining - loonie * 100;
	printf("$1.00 Loonies  X %d (remaining: $%0.2f)\n", loonie, (float)remaining / 100.0);

	quarter = (remaining - remaining % 25) / 25;
	remaining = remaining - quarter * 25;
	printf("$0.25 Quarters X %d (remaining: $%0.2f)\n", quarter, (float)remaining / 100.0);

	dime = (remaining - remaining % 10) / 10;
	remaining = remaining - dime * 10;
	printf("$0.10 Dimes    X %d (remaining: $%0.2f)\n", dime, (float)remaining / 100.0);

	nickel = (remaining - remaining % 5) / 5;
	remaining = remaining - nickel * 5;
	printf("$0.05 Nickels  X %d (remaining: $%0.2f)\n", nickel, (float)remaining / 100.0);

	penny = remaining - remaining % 1;
	remaining = remaining - penny * 1;
	printf("$0.01 Pennies  X %d (remaining: $%0.2f)\n", penny, (float)remaining / 100.0);

	printf("\n");
	printf("All coins dispensed!\n");
	return 0;
}