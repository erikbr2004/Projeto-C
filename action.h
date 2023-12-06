#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void removeLineFromFile(FILE* file, int lineToRemove);		// Função para remover um produto de um arquivo
void addProd(FILE* file, int idProd, int amount);	// Função para adicionar um valor a um ID de produto específico
void rmvProd(FILE* file, int idProd, int amount);	// Função para remover um valor de um ID de produto específico
