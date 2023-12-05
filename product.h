#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct
{
	int productId;
	char productName[50];
	float productPrice;
	int productMaxQuantity;
	int productQuantity;
}Product;

void createProd(FILE* file, char* nameProd, float priceProd, int maxQuantityProd, int quantityProd);	// Function to create a new product entry in a file
void deleteProd(FILE* file, int idProd);	// Function to delete a product from the file based on the specified ID
void checkProd(FILE* file, int idProd);		// Function to check and display information about a product with a given ID in a file
void listOfProd(FILE* file);	// Function to list all products from a file