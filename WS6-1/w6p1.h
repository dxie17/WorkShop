/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :Deyang Xie
	ID     :150162204
	Email  :dxie17@myseneca.ca
	Section:NGG
*/

#define MAX_products 3
#define num_grams 64

// ----------------------------------------------------------------------------
// structures
typedef  struct
{
	int sku;
	double price;
	int calories;
	double weight;
} CatFoodInfo;

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

// 7. Logic entry point
void start();