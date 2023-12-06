#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "product.h"

void menuCreateProd(FILE* file, int* isRunning);		// Function to create a new product in the file
void menuDeleteProd(FILE* file, int* isRunning, int idProd);	// Function to delete a product from the file
void menuAddRmvProd(FILE* file, int* isRunning, int idProd);	// Function to add or remove quantity from a product in the file
void menuCheckProd(FILE* file, int* isRunning, int idProd);		// Function to check details of a product in the file
void menuListProd(FILE* file, int* isRunning);		// Function to list all products in the file
void menu(FILE* file, int* isRunning);		// Main menu function to manage user choices