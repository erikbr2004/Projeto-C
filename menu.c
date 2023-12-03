#include "menu.h"

void menuCreateProd(int* isRunning, Product* ptrProd, int* ptrProdQuantity)
{
	int option;
	char nameCreateProd[50];
	float priceAddProd;
	int quantityAddProd;

	system("cls");
	printf("Enter product name: ");
	scanf_s(" %s", nameCreateProd, sizeof(nameCreateProd));
	printf("Enter product price: ");
	scanf_s("%f", &priceAddProd);
	printf("Enter product quantity: ");
	scanf_s("%d", &quantityAddProd);
	
	//*ptrProdQuantity++;
	//ptrProd = (Product*)realloc(ptrProd, sizeof(Product) * *ptrProdQuantity);
	//if (!ptrProd)
	//{
		//return EXIT_FAILURE;
	//}
	//createProd(nameCreateProd, priceAddProd, quantityAddProd);

	printf("Product created with success!\n");
	Sleep(1000);

	system("cls");
	printf("1) Create another product\n2) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		menuCreateProd(isRunning, ptrProd, ptrProdQuantity);
		break;
	case 2:
		menu(isRunning, ptrProd);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuDeleteProd(int* isRunning, int idProd, Product* ptrProd)
{
	int option;
	int newProd;
	char check;

	system("cls");
	printf("Are you sure you want to delete [NOME PROD] from product list? Y/N: ");
	scanf_s(" %c", &check);

	switch (check)
	{
	case 'y':
	case 'Y':
		//funcao para deletar produto da lista de produto com parametro idProd
		//

		break;
	case 'n':
	case 'N':
		system("cls");
		printf("Operation aborted!\n");
		Sleep(800);
		break;
	default:
		printf("Invalid Operation!\n");
		break;
	}

	system("cls");

	printf("1) Delete another product\n2) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		printf("Enter new product ID: ");
		scanf_s("%d", &newProd);
		menuDeleteProd(isRunning, newProd, ptrProd);
		break;
	case 2:
		menu(isRunning, ptrProd);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuAddRmvProd(int* isRunning, int idProd, Product* ptrProd)
{
	int quantity;

	system("cls");
	printf("Enter the desired amount: ");
	scanf_s("%d", &quantity);

	//funcao para adicionar ou remover certa qntd de um produto utilizando parametro idProd
	//

	printf("Success!");
	Sleep(1000);

	menu(isRunning, ptrProd);
}

void menuCheckProd(int* isRunning, Product* ptrProd)
{
	int option;
	int idProd;
	
	system("cls");
	printf("Enter product ID: ");
	scanf_s("%d", &idProd);

	//funcao para checar qnt do produto
	//

	printf("1) Check another product\n2) Add/Remove product quantity\n3) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		menuCheckProd(isRunning, ptrProd);
		break;
	case 2:
		menuAddRmvProd(isRunning, idProd, ptrProd);
		break;
	case 3:
		menu(isRunning, ptrProd);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuListProd(int* isRunning, Product* ptrProd)
{
	int option;
	system("cls");
	//funcao para exibir todos os produtos ja registrados
	//

	printf("1) List products again\n2) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);
	
	switch (option)
	{
	case 1:
		menuListProd(isRunning, ptrProd);
		break;
	case 2:
		menu(isRunning, ptrProd);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menu(int* isRunning, Product* ptrProd)
{
	system("cls");
	int option;
	int idProd;
	int prodQuantity = 0;
	int* ptrProdQuantity = &prodQuantity;

	while (*isRunning)
	{
		printf("1) Create a product\n");
		printf("2) Delete a product\n");
		printf("3) Check a product amount\n");
		printf("4) Add/Remove Product Quantity\n");
		printf("5) List existing products\n");
		printf("0) Exit program\n");
		printf("Select an option: ");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			menuCreateProd(isRunning, ptrProd, ptrProdQuantity);
			break;
		case 2:
			system("cls");
			printf("Enter the desired product ID: ");
			scanf_s("%d", &idProd);
			menuDeleteProd(isRunning, idProd, ptrProd);
			break;
		case 3:
			menuCheckProd(isRunning, ptrProd);
			break;
		case 4:
			system("cls");
			printf("Enter the desired product ID: ");
			scanf_s("%d", &idProd);
			menuAddRmvProd(isRunning, idProd, ptrProd);
			break;
		case 5:
			menuListProd(isRunning, ptrProd);
			break;
		case 0:
			*isRunning = 0;
			break;
		default:
			printf("Invalid Operation! Try again.\n");
			break;
		}
	}

	system("cls");
	printf("Exiting.");
	Sleep(275);
	system("cls");
	printf("Exiting..");
	Sleep(275);
	system("cls");
	printf("Exiting...");
	Sleep(190);
}