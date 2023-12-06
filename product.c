#include "product.h"
#include "action.h"

const char* PRODUCT_FORMAT_IN = "Id: %d, Name: %[^,], Price: $%f, Max Quantity: %d, Quantity: %d\n";	// Input format string for reading product details from a file
const char* PRODUCT_FORMAT_OUT = "Id: %5d, Name: %25s, Price: $%8.2f, Max Quantity: %4d, Quantity: %4d\n";    // Output format string for writing product details to a file

void createProd(FILE* file, char* nameProd, float priceProd, int maxQuantityProd, int quantityProd)
{
    Product prod;

    rewind(file);	// Move the file cursor to the beginning of the file

    // Read the existing product entries to find the last product ID
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF);
	prod.productId++;

	// Write the new product entry to the file
    fprintf(file, PRODUCT_FORMAT_OUT, prod.productId, nameProd, priceProd, maxQuantityProd, quantityProd);
}

void deleteProd(FILE* file, int idProd)
{
    Product prod;

	char check;
    int lineToRemove = 1;

    rewind(file);	// Move the file cursor to the beginning of the file

	// Search for the product with the specified ID
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF && prod.productId != idProd)
    {
        ++lineToRemove;
    }

	system("cls");

    if (prod.productId == idProd)   // Check if the product with the specified ID was found
    {
        // Prompt the user for confirmation
        printf("Are you sure you want to DELETE %s (Product ID: %d) from the product list? Y/N: ", prod.productName, prod.productId);
        scanf_s(" %c", &check, 1);

        switch (check)
        {
        case 'y':
        case 'Y':
            // User confirmed deletion, perform the deletion
            removeLineFromFile(file, lineToRemove);
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

void addRmvProd(FILE* file, int idProd)
{
    Product prod;

    char check;
    int amount;

    rewind(file);   // Move the file cursor to the beginning of the file

    // Search for the product with the specified ID
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF && prod.productId != idProd);

    if (prod.productId == idProd)   // Check if the product with the specified ID was found
    {
        // Print the details of the found product
        printf(PRODUCT_FORMAT_OUT, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);

        // Prompt the user for the desired operation
        printf("Enter desired operation to be performed\nA: to add\nR: to remove\nQ: to abort\nOption: ");
        scanf_s(" %c", &check, 1);

        switch (check)
        {
        case 'a':
        case 'A':
            // Prompt the user to enter the amount to add
            printf("Enter desired amount to add: ");
            scanf_s(" %d", &amount);

            // Check if adding the specified amount will exceed the maximum quantity
            if (prod.productQuantity + amount > prod.productMaxQuantity)
            {
                printf("Invalid amount! Product quantity will be bigger than product max quantity!");
                Sleep(1200);
                break;
            }
            // Call the addProd function to perform the addition
            addProd(file, idProd, amount);
            break;
        case 'r':
        case 'R':
            // Prompt the user to enter the amount to remove
            printf("Enter desired amount to remove: ");
            scanf_s(" %d", &amount);

            // Check if removing the specified amount will result in a negative quantity
            if (prod.productQuantity - amount < 0)
            {
                printf("Invalid amount! Product quantity will be negative!");
                Sleep(1200);
                break;
            }
            // Call the rmvProd function to perform the removal
            rmvProd(file, idProd, amount);
            break;
        case 'q':
        case 'Q':
            // Abort the operation
            printf("Operation aborted!");
            Sleep(800);
            break;
        default:
            // Invalid operation entered
            printf("Invalid operation!");
            Sleep(1000);
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
    Product prod;

    rewind(file);	// Move the file cursor to the beginning of the file

    // Search for the product with the specified ID
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF && prod.productId != idProd);

    if (prod.productId == idProd)   // Check if the product with the specified ID was found
    {
        // Display information about the found product
        printf(PRODUCT_FORMAT_OUT, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);
        if (prod.productQuantity < prod.productMaxQuantity * 0.37)
        {
            printf("The amount of %s is less than 37%% in stock!\nRestock recommended.", prod.productName);
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
    Product prod;

    rewind(file);	// Move file cursor to the beginning of the file

    // Read and print each product entry until the end of the file
	while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF)
	{
		printf(PRODUCT_FORMAT_OUT, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);	// Print the details of the current product
	}
}
