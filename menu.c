#include "menu.h"

void menuCreateProd(int* isRunning)
{
	int option;
	char nomeCreateProd[50];
	float precoAddProd;

	system("cls");
	printf("Enter product name: ");
	scanf_s("%s", nomeCreateProd, sizeof(nomeCreateProd));
	printf("Enter product price: ");
	scanf_s("%f", &precoAddProd);
	
	//funçao para criar um produto
	//
	printf("Product created with success!\n");
	Sleep(1000);

	system("cls");
	printf("1) Create another product\n2) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		menuCreateProd(isRunning);
		break;
	case 2:
		menu(isRunning);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuAddRmvProd(int* isRunning, int idProd)
{
	int quantity;

	system("cls");
	printf("Enter the desired amount: ");
	scanf_s("%d", &quantity);

	//funcao para adicionar ou remover certa qntd de um produto utilizando parametro idProd
	//

	printf("Success!");
	Sleep(1000);

	menu(isRunning);
}

void menuCheckProd(int* isRunning)
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
		menuCheckProd(isRunning);
		break;
	case 2:
		menuAddRmvProd(isRunning, idProd);
		break;
	case 3:
		menu(isRunning);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuListProd(int* isRunning)
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
		menuListProd(isRunning);
		break;
	case 2:
		menu(isRunning);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menu(int* isRunning)
{
	system("cls");
	int option;
	int idProd;
	while (*isRunning)
	{
		printf("1) Create a product\n");
		printf("2) Check a product amount\n");
		printf("3) Add/Remove Product Quantity\n");
		printf("4) List existing products\n");
		printf("0) Exit program\n");
		printf("Select an option: ");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			menuCreateProd(isRunning);
			break;
		case 2:
			menuCheckProd(isRunning);
			break;
		case 3:
			printf("Enter the product ID: ");
			scanf_s("%d", &idProd);
			menuAddRmvProd(isRunning, idProd);
			break;
		case 4:
			menuListProd(isRunning);
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