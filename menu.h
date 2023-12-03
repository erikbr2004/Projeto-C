#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "product.h"

void menuCreateProd(int* isRunning, Product* ptrProd, int* prodQuantity);
void menuDeleteProd(int* isRunning, int idProd, Product* ptrProd);
void menuAddRmvProd(int* isRunning, int idProd, Product* ptrProd);
void menuCheckProd(int* isRunning, Product* ptrProd);
void menuListProd(int* isRunning, Product* ptrProd);
void menu(int* isRunning, Product* ptrProd);