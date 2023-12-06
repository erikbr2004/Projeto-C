#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "product.h"

void menuCreateProd(FILE* file, int* isRunning);		// Função para criar um novo produto no arquivo
void menuDeleteProd(FILE* file, int* isRunning, int idProd);	// Função para excluir um produto do arquivo
void menuAddRmvProd(FILE* file, int* isRunning, int idProd);	// Função para adicionar ou remover quantidade de um produto no arquivo
void menuCheckProd(FILE* file, int* isRunning, int idProd);		// Função para verificar detalhes de um produto no arquivo
void menuListProd(FILE* file, int* isRunning);		// Função para listar todos os produtos do arquivo
void menu(FILE* file, int* isRunning);		// Função do menu principal para gerenciar as escolhas do usuário
