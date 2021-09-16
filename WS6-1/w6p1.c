/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :Deyang Xie
	ID     :150162204
	Email  :dxie17@myseneca.ca
	Section:NGG
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	int num = 0;
	while (num <= 0)
	{
		scanf("%d", &num);
		if (num <= 0)
			printf("ERROR: Enter a positive value: ");
	}
	if (number != NULL)
		*number = num;
	return num;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number)
{
	double num = 0.0;
	while (num <= 0)
	{
		scanf("%lf", &num);
		if (num <= 0)
			printf("ERROR: Enter a positive value: ");
	}
	if (number != NULL)
		*number = num;
	return num;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_products)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_products);
	printf("NOTE: A 'serving' is 64g\n");
}

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(int sku)
{
	CatFoodInfo catfood;
	double price = 0.0;
	printf("PRICE         : $");
	while (price <= 0)
		price = getDoublePositive(NULL);
	catfood.price = price;

	double weight = 0.0;
	printf("WEIGHT (LBS)  : ");
	while (weight <= 0)
		weight = getDoublePositive(NULL);
	catfood.weight = weight;

	int calories = 0;
	printf("CALORIES/SERV.: ");
	while (calories <= 0)
		calories = getDoublePositive(NULL);
	catfood.calories = calories;

	return catfood;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, double* weight, int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point

void start()
{
	int i = 0, sku = 0;
	CatFoodInfo catfood[MAX_products];
	openingMessage(MAX_products);

	for (i = 0; i < MAX_products; i++)
	{
		printf("\nCat Food Product #%d\n", i + 1);
		printf("--------------------\n");
		printf("SKU           : ");
		sku = 0;
		while (sku <= 0)
			sku = getIntPositive(NULL);
		catfood[i] = getCatFoodInfo(sku);
		catfood[i].sku = sku;
	}

	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAX_products; i++)
		displayCatFoodData(catfood[i].sku, &catfood[i].price, &catfood[i].weight, catfood[i].calories);
	return;
}