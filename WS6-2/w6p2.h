/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :Deyang Xie
	ID     :150162204
	Email  :dxie17@myseneca.ca
	Section:NGG
*/

#define MAX_products 3
#define num_grams 64
#define lbs2kg 2.20462

// ----------------------------------------------------------------------------
// structures
typedef  struct
{
	int sku;
	double price;
	int calories;
	double weight;
} CatFoodInfo;

typedef  struct
{
	int sku;
	double price;
	int calories;
	double weight_lbs;
	double weight_kg;
	int weight_g;
	double totalservings;
	double c_per_serving;
	double c_cal_per_serving;
}	ReportData;


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_products);

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(int sku);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, double* weight, int calories);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(double* weight_lbs, double* weight_kg);

// 9. convert lbs: g
int convertLbsG(double* weight_lbs, int* weight_g);

// 10. convert lbs: kg / g
void convertLbs(double* weight_lbs, double* weight_kg, int* weight_g);

// 11. calculate: servings based on gPerServ
double calculateServings(int g_serings, int totalgrams, double* num_servings);

// 12. calculate: cost per serving
double calculateCostPerServing(double* price, double* num_servings, double* c_per_serving);

// 13. calculate: cost per calorie
double calculateCostPerCal(double* price, double* total_num_cal, double* c_per_cal);

// 14. Derive a reporting detail record based on the cat food product data
ReportData calculateReportData(CatFoodInfo catfood);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(ReportData reportdata[MAX_products], int sku);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(CatFoodInfo cheapest);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start();