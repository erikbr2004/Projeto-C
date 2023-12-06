#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct
{
	int productId;
	char productName[50];
	float productPrice;
	int productMaxQuantity;
	int productQuantity;
}Product;

void createProd(FILE* file, char* nameProd, float priceProd, int maxQuantityProd, int quantityProd);	// Função para criar uma nova entrada de produto em um arquivo
void deleteProd(FILE* file, int idProd);	// Função para excluir um produto do arquivo com base no ID especificado
void addRmvProd(FILE* file, int idProd);	// Função para adicionar ou remover uma quantidade específica de um produto
void checkProd(FILE* file, int idProd);		// Função para verificar e exibir informações sobre um produto com um determinado ID em um arquivo
void listOfProd(FILE* file);	// Função para listar todos os produtos de um arquivo
