#include "product.h"

const char* PRODUCT_FORMAT_IN = "Id: %d, Name: %[^,], Price: $%f, Max Quantity: %d, Quantity: %d\n";	// Input format string for reading product details from a file
const char* PRODUCT_FORMAT_OUT = "Id: %d, Name: %s, Price: $%.2f, Max Quantity: %d, Quantity: %d\n";	// Output format string for writing product details to a file

// Variables to store the details of the last read product
int     lastProdId = 0;               // Last product ID
char    lastProdName[50];             // Last product name (up to 50 characters)
float   lastProdPrice = 0;            // Last product price
int     lastProdMaxQuantity = 0;      // Last product max quantity
int     lastProdQuantity = 0;         // Last product quantity



void createProd(FILE* file, char* nameProd, float priceProd, int maxQuantityProd, int quantityProd)
{
	fseek(file, 0, SEEK_SET);	// Move the file cursor to the beginning of the file

    // Read the existing product entries to find the last product ID
	while (fscanf_s(file, PRODUCT_FORMAT_IN, &lastProdId, lastProdName, 50, &lastProdPrice, &lastProdMaxQuantity, &lastProdQuantity) != EOF);
	lastProdId++;

	// Write the new product entry to the file
    fprintf(file, PRODUCT_FORMAT_OUT, lastProdId, nameProd, priceProd, maxQuantityProd, quantityProd);
}

void deleteProd(FILE* file, int idProd)
{
	char check;

	fseek(file, 0, SEEK_SET);	// Move the file cursor to the beginning of the file

	// Search for the product with the specified ID
	while (fscanf_s(file, PRODUCT_FORMAT_IN, &lastProdId, lastProdName, 50, &lastProdPrice, &lastProdMaxQuantity, &lastProdQuantity) != EOF && lastProdId != idProd);

	system("cls");

    if (lastProdId == idProd)   // Check if the product with the specified ID was found
    {
        // Prompt the user for confirmation
        printf("Are you sure you want to DELETE %s (Product ID: %d) from the product list? Y/N: ", lastProdName, lastProdId);
        scanf_s(" %c", &check, 1);

        switch (check)
        {
        case 'y':
        case 'Y':
            // User confirmed deletion, perform the deletion
            // COMPLETE HERE
            
            printf("Product deleted successfully!");
            Sleep(800);
            break;
        case 'n':
        case 'N':
            // User chose not to delete, inform and abort
            system("cls");
            printf("Operation aborted!\n");
            Sleep(800);
            break;
        default:
            // Invalid user input
            printf("Invalid Operation!\n");
            Sleep(800);
            break;
        }
    }
    else
    {
        // Product with the specified ID not found
        printf("Product with ID %d not found!\n", idProd);
        Sleep(800);
    }
}

void checkProd(FILE* file, int idProd)
{
    fseek(file, 0, SEEK_SET);	// Move the file cursor to the beginning of the file

    // Search for the product with the specified ID
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &lastProdId, lastProdName, 50, &lastProdPrice, &lastProdMaxQuantity, &lastProdQuantity) != EOF && lastProdId != idProd);

    if (lastProdId == idProd)   // Check if the product with the specified ID was found
    {
        printf(PRODUCT_FORMAT_OUT, lastProdId, lastProdName, lastProdPrice, lastProdMaxQuantity, lastProdQuantity);
        if (lastProdQuantity < lastProdMaxQuantity * 0.37)
        {
            printf("The amount of %s is less than 37%% in stock!\nRestock recommended.", lastProdName);
        }
    }
    else
    {
        // Product with the specified ID not found
        printf("Product with ID %d not found!\n", idProd);
        Sleep(800);
    }
}

void listOfProd(FILE* file)
{
	fseek(file, 0, SEEK_SET);	// Move the file cursor to the beginning of the file

    // Read and print each product entry until the end of the file
	while (fscanf_s(file, PRODUCT_FORMAT_IN, &lastProdId, lastProdName, 50, &lastProdPrice, &lastProdMaxQuantity, &lastProdQuantity) != EOF)
	{
		printf(PRODUCT_FORMAT_OUT, lastProdId, lastProdName, lastProdPrice, lastProdMaxQuantity, lastProdQuantity);	// Print the details of the current product
	}
}

/*// Define the dimensions of the matrix
int rows = 3;
int cols = 3;

// Declare a matrix of pointers to Product structures
Product** productMatrix = (Product**)malloc(rows * sizeof(Product*));

// Initialize the matrix and allocate memory for each Product
for (int i = 0; i < rows; ++i)
{
    productMatrix[i] = (Product*)malloc(cols * sizeof(Product));
}*/