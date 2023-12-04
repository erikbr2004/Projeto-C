#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct
{
	int productId;
	char* productName;
	float productPrice;
	int productMaxQuantity;
	int productQuantity;
}Product;

void createProd(FILE* file, char* nameProd, float priceProd, int maxQuantityProd, int productQuantity);	// Function to create a new product entry in a file
void deleteProd(FILE* file, int idProd);	// Function to delete a product from the file based on the specified ID
void checkProd(FILE* file, int idProd);		
void listOfProd(FILE* file);	// Function to list all products from a file