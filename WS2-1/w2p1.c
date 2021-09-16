/*
	==================================================
	Workshop #2 (Part-1):
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
	float amount, remaining;
	int toonie, loonie, quarter;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%f", &amount);
	toonie = amount / 2;
	remaining = amount - toonie * 2;
	printf("\n");
	printf("$2.00 Toonies  X %d(remaining: $%0.2f)\n", toonie, remaining);
	loonie = remaining / 1;
	remaining = remaining - loonie * 1;
	printf("$1.00 Loonies  X %d(remaining: $%0.2f)\n", loonie, remaining);
	quarter = remaining / 0.25;
	remaining = remaining - quarter * 0.25;
	printf("$0.25 Quarters X %d(remaining: $%0.2f)\n", quarter, remaining);
	printf("\n");
	printf("Machine error! Thank you for letting me keep $%0.2f!", remaining);
	return 0;
}