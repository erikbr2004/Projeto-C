#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "product.h"

void menuCreateProd(FILE* file, int* isRunning);
void menuDeleteProd(FILE* file, int* isRunning, int idProd);
void menuAddRmvProd(FILE* file, int* isRunning, int idProd);
void menuCheckProd(FILE* file, int* isRunning, int idProd);
void menuListProd(FILE* file, int* isRunning);
void menu(FILE* file, int* isRunning);