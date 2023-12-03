#include "menu.h"
#include "product.h"

int main()
{
	Product prod;
	ptrProduct ptrProd;

	int run = 1;
	int* ptrRun = &run;

	menu(ptrRun, ptrProd);

	free(ptrProd);

	return EXIT_SUCCESS;
}