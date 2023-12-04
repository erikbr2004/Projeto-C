#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "product.h"

int main()
{
	FILE* file;
	fopen_s(&file, "product.txt", "r+");
	
	if (!file)
	{
		printf("Error opening file!");
		return EXIT_FAILURE;
	}

	int run = 1;
	int* ptrRun = &run;

	menu(file, ptrRun);

	fclose(file);

	return EXIT_SUCCESS;
}