#include "menu.h"

void menuCreateProd(FILE* file, int* isRunning)
{
	int option;
	char nameCreateProd[50];
	float priceAddProd;
	int maxQuantityAddProd;
	int quantityAddProd;

	system("cls");
	printf("Enter product name: ");
	scanf_s(" %[^\n]", nameCreateProd, 50);
	printf("Enter product price: ");
	scanf_s(" %f", &priceAddProd);
	printf("Enter product max stock quantity: ");
	scanf_s(" %d", &maxQuantityAddProd);
	printf("Enter product quantity: ");
	scanf_s(" %d", &quantityAddProd);
	
	createProd(file, nameCreateProd, priceAddProd, maxQuantityAddProd, quantityAddProd);

	printf("Product created with success!\n");
	Sleep(1000);

	system("cls");
	printf("1) Create another product\n2) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		menuCreateProd(file, isRunning);
		break;
	case 2:
		menu(file, isRunning);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuDeleteProd(FILE* file, int* isRunning, int idProd)
{
	int option;
	int newProd;

	deleteProd(file, idProd);	//FALTA COISA NA FUNCAO

	system("cls");

	printf("1) Delete another product\n2) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		system("cls");
		printf("Enter new product ID: ");
		scanf_s("%d", &newProd);
		menuDeleteProd(file, isRunning, newProd);
		break;
	case 2:
		menu(file, isRunning);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuAddRmvProd(FILE* file, int* isRunning, int idProd)
{
	int quantity;

	system("cls");
	printf("Enter the desired amount: ");
	scanf_s("%d", &quantity);

	//funcao para adicionar ou remover certa qntd de um produto utilizando parametro idProd
	//

	printf("Success!");
	Sleep(1000);

	menu(file, isRunning);
}

void menuCheckProd(FILE* file, int* isRunning, int idProd)
{
	int option;
	int newProd;
	
	system("cls");

	checkProd(file, idProd);

	printf("\n1) Check another product\n2) Add/Remove product quantity\n3) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		printf("Enter new product ID: ");
		scanf_s("%d", &newProd);
		menuCheckProd(file, isRunning, newProd);
		break;
	case 2:
		menuAddRmvProd(file, isRunning, idProd);
		break;
	case 3:
		menu(file, isRunning);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menuListProd(FILE* file, int* isRunning)
{
	int option;
	system("cls");

	listOfProd(file);

	printf("1) List products again\n2) Go back to main menu\n0) Exit program\n");
	printf("Select an option: ");
	scanf_s("%d", &option);
	
	switch (option)
	{
	case 1:
		menuListProd(file, isRunning);
		break;
	case 2:
		menu(file, isRunning);
		break;
	case 0:
		*isRunning = 0;
		break;
	default:
		printf("Invalid Operation! Going back to main menu.\n");
		break;
	}
}

void menu(FILE* file, int* isRunning)
{
	system("cls");
	int option;
	int idProd;

	while (*isRunning)
	{
		printf("1) Create a product\n");
		printf("2) Delete a product\n");
		printf("3) Check a product amount\n");
		printf("4) Add/Remove product quantity\n");
		printf("5) List existing products\n");
		printf("0) Exit program\n");
		printf("Select an option: ");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			menuCreateProd(file, isRunning);
			break;
		case 2:
			system("cls");
			printf("Enter the desired product ID: ");
			scanf_s("%d", &idProd);
			menuDeleteProd(file, isRunning, idProd);
			break;
		case 3:
			system("cls");
			printf("Enter the desired product ID: ");
			scanf_s("%d", &idProd);
			menuCheckProd(file, isRunning, idProd);
			break;
		case 4:
			system("cls");
			printf("Enter the desired product ID: ");
			scanf_s("%d", &idProd);
			menuAddRmvProd(file, isRunning, idProd);
			break;
		case 5:
			menuListProd(file, isRunning);
			break;
		case 0:
			*isRunning = 0;
			break;
		default:
			printf("Invalid Operation! Try again.\n");
			break;
		}
	}


}