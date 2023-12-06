#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void removeLineFromFile(FILE* file, int lineToRemove);		// Function to remove a product frin a file
void addProd(FILE* file, int idProd, int amount);	// Function to add an amount to a specific product ID
void rmvProd(FILE* file, int idProd, int amount);	// Function to remove an amount to a specific product ID