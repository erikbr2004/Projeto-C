#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct
{
	int productId;
	char productName[50];
	float productPrice;
	int productQuantity;
}Product, *ptrProduct;

Product createProd(char nameProd, float priceProd, int quantidade);