/*
	==================================================
	Workshop #6 (Part-2):
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
#include "w6p2.h"

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double* weight_lbs, double* weight_kg)
{
	double weightofkg = 0;
	if (weight_kg == NULL && weight_lbs != NULL)
		weightofkg = *weight_lbs / lbs2kg;
	else if (weight_kg != NULL && weight_lbs != NULL)
	{
		*weight_kg = *weight_lbs / lbs2kg;
		weightofkg = *weight_kg;
	}
	return weightofkg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(double* weight_lbs, int* weight_g)
{
	int weightofg = 0;
	if (weight_g == NULL)
		weightofg = *weight_lbs / lbs2kg * 1000;
	else if (weight_g != NULL)
	{
		*weight_g = *weight_lbs / lbs2kg * 1000;
		weightofg = *weight_g;
	}
	return weightofg;
}

// 10. convert lbs: kg and g
void convertLbs(double* weight_lbs, double* weight_kg, int* weight_g)
{
	*weight_kg = *weight_lbs / lbs2kg;
	*weight_g = *weight_lbs / lbs2kg * 1000;
	return;
}

// 11. calculate: servings based on gPerServ
double calculateServings(int g_serings, int totalgrams, double* num_servings)
{
	double numofservings = 0;
	g_serings = num_grams;
	if (num_servings == NULL)
		numofservings = (double)totalgrams / (double)g_serings;
	else if (num_servings != NULL)
	{
		*num_servings = (double)(totalgrams / g_serings);
		numofservings = *num_servings;
	}
	return numofservings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(double* price, double* num_servings, double* c_per_serving)
{
	double cofperofserving = 0;
	if (c_per_serving == NULL)
		cofperofserving = *price / *num_servings;
	else if (c_per_serving != NULL)
	{
		*c_per_serving = *price / *num_servings;
		cofperofserving = *c_per_serving;
	}
	return cofperofserving;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(double* price, double* total_num_cal, double* c_per_cal)
{
	double cofperofcal = 0;
	if (c_per_cal == NULL)
		cofperofcal = *price / *total_num_cal;
	else if (c_per_cal != NULL)
	{
		*c_per_cal = *price / *total_num_cal;
		cofperofcal = *c_per_cal;
	}
	return cofperofcal;
}

// 14. Derive a reporting detail record based on the cat food product data
ReportData calculateReportData(CatFoodInfo catfood)
{
	double total_num_cal = 0;
	ReportData reportdata = { 0 };
	reportdata.sku = catfood.sku;
	reportdata.price = catfood.price;
	reportdata.calories = catfood.calories;
	reportdata.weight_lbs = catfood.weight;
	reportdata.weight_kg = convertLbsKg(&reportdata.weight_lbs, NULL);
	reportdata.weight_g = convertLbsG(&reportdata.weight_lbs, NULL);
	reportdata.totalservings = calculateServings(64, reportdata.weight_g, NULL);
	reportdata.c_per_serving = calculateCostPerServing(&reportdata.price, &reportdata.totalservings, NULL);
	total_num_cal = reportdata.totalservings * reportdata.calories;
	reportdata.c_cal_per_serving = calculateCostPerCal(&reportdata.price, &total_num_cal, NULL);
	return reportdata;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg\n", num_grams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(ReportData reportdata[MAX_products], int sku)
{
	int i = 0;
	for (i = 0; i < MAX_products; i++)
	{
		printf("%07d      %5.2lf", reportdata[i].sku, reportdata[i].price);
		printf("       %4.1lf     %6.4lf", reportdata[i].weight_lbs, reportdata[i].weight_kg);
		printf("      %d      %d", reportdata[i].weight_g, reportdata[i].calories);
		printf("     %4.1lf    %4.2lf", reportdata[i].totalservings, reportdata[i].c_per_serving);
		printf(" %7.5lf", reportdata[i].c_cal_per_serving);

		if (reportdata[i].sku == sku)
			printf(" ***\n");
		else
			printf("\n");
	}
	return;
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(CatFoodInfo cheapest)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cheapest.sku, cheapest.price);
	printf("\nHappy shopping!\n");

}

// ----------------------------------------------------------------------------


// 7. Logic entry point

void start()
{
	int i = 0, sku = 0, sku_cheapest = 0;
	CatFoodInfo catfood[MAX_products];
	ReportData reportdata[MAX_products];
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

	displayReportHeader();


	for (i = 0; i < MAX_products; i++)
	{
		reportdata[i] = calculateReportData(catfood[i]);
		if (i > 0 && reportdata[i].c_cal_per_serving > reportdata[i - 1].c_cal_per_serving)
			sku_cheapest = reportdata[i - 1].sku;
		else
			sku_cheapest = reportdata[i].sku;
	}
	displayReportData(reportdata, sku_cheapest);

	for (i = 0; i < MAX_products; i++)
	{
		if (catfood[i].sku == sku_cheapest)
		{
			catfood[0].sku = catfood[i].sku;
			catfood[0].price = catfood[i].price;
			catfood[0].calories = catfood[i].calories;
			catfood[0].weight = catfood[i].weight;
		}
	}
	displayFinalAnalysis(catfood[0]);

	return;
}