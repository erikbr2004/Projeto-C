#include "action.h"
#include "product.h"

const char* PRODUCT_FORMAT_INP = "Id: %d, Name: %[^,], Price: $%f, Max Quantity: %d, Quantity: %d\n";	// Input format string for reading product details from a file
const char* PRODUCT_FORMAT_OUTP = "Id: %5d, Name: %25s, Price: $%8.2f, Max Quantity: %4d, Quantity: %4d\n";    // Output format string for writing product details to a file

void removeLineFromFile(FILE* file, int lineToRemove)
{
    // Create a temporary file
    FILE* tempFile;
    tmpfile_s(&tempFile);
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        return;
    }

    // Copy lines to the temporary file, excluding the specified line
    int currentLine = 1;
    char buffer[1024];

    rewind(file);   // Rewind to the beginning of the original file

    while (fgets(buffer, sizeof(buffer), file) != NULL)     // Get every information saving in a buffer
    {
        // Check if currentLine is not desired line to remove
        if (currentLine != lineToRemove)
        {
            fputs(buffer, tempFile);    // Save info from buffer in tempFile
        }

        currentLine++;
    }

    rewind(tempFile);   // Rewind to the beginning of the temporary file

    rewind(file);   // Copy contents of the temporary file back to the original file

    freopen_s(&file, "product.txt", "w", file);     // Deletes every content from file

    freopen_s(&file, "product.txt", "r+", file);    // Reopen file in read/write mode

    while (fgets(buffer, sizeof(buffer), tempFile) != NULL)     // Writes every data saved in tempFile in file
    {
        fputs(buffer, file);
    }

    remove("temp.txt");

    fclose(tempFile);   // Close the temporary file
}

void addProd(FILE* file, int idProd, int amount)
{
    // Create a temporary file
    FILE* tempFile;
    tmpfile_s(&tempFile);
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        return;
    }

    Product prod;

    char buffer[1024];
    int id = 0;

    // Rewind to the beginning of the original file
    rewind(file);

    // Read each line from the original file
    while (fscanf_s(file, PRODUCT_FORMAT_INP, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF)
    {
        if (prod.productId == idProd)
        {
            // Found the product to update
            prod.productQuantity += amount;
            id = prod.productId;
        }

        // Write the modified or unmodified line to the temporary file
        fprintf(tempFile, PRODUCT_FORMAT_OUTP, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);
    }

    rewind(tempFile);   // Rewind to the beginning of the temporary file

    rewind(file);   // Rewind to the beginning of the original file

    freopen_s(&file, "product.txt", "w", file);     // Deletes every content from file

    freopen_s(&file, "product.txt", "r+", file);    // Reopen file in read/write mode

    while (fgets(buffer, sizeof(buffer), tempFile) != NULL)     // Writes every data saved in tempFile in file
    {
        fputs(buffer, file);
    }

    remove("temp.txt");

    fclose(tempFile);   // Close the temporary file

    printf("Amount successfuly added to ID %d", id);
    Sleep(800);
}

void rmvProd(FILE* file, int idProd, int amount)
{
    // Create a temporary file
    FILE* tempFile;
    tmpfile_s(&tempFile);
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        return;
    }

    Product prod;

    char buffer[1024];
    int id = 0;

    // Rewind to the beginning of the original file
    rewind(file);

    // Read each line from the original file
    while (fscanf_s(file, PRODUCT_FORMAT_INP, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF)
    {
        if (prod.productId == idProd)
        {
            // Found the product to update
            prod.productQuantity -= amount;
            id = prod.productId;
        }

        // Write the modified or unmodified line to the temporary file
        fprintf(tempFile, PRODUCT_FORMAT_OUTP, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);
    }

    rewind(tempFile);   // Rewind to the beginning of the temporary file

    rewind(file);   // Rewind to the beginning of the original file

    freopen_s(&file, "product.txt", "w", file);     // Deletes every content from file

    freopen_s(&file, "product.txt", "r+", file);    // Reopen file in read/write mode

    while (fgets(buffer, sizeof(buffer), tempFile) != NULL)     // Writes every data saved in tempFile in file
    {
        fputs(buffer, file);
    }

    remove("temp.txt");

    fclose(tempFile);   // Close the temporary file

    printf("Amount successfuly removed from ID %d", id);
    Sleep(800);
}
