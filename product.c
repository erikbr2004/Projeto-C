#include "product.h"
#include "action.h"

const char* PRODUCT_FORMAT_IN = "Id: %d, Name: %[^,], Price: $%f, Max Quantity: %d, Quantity: %d\n";	// String para um formato de entrada para leitura de detalhes do produto em um arquivo
const char* PRODUCT_FORMAT_OUT = "Id: %5d, Name: %25s, Price: $%8.2f, Max Quantity: %4d, Quantity: %4d\n";    // String para um formato de saida para impressao de detalhes do produto de um arquivo

void createProd(FILE* file, char* nameProd, float priceProd, int maxQuantityProd, int quantityProd)
{
    Product prod;

    rewind(file);	// Move o cursor para o inicio do arquivo

    // Le as entradas de produtos existentes para encontrar o último ID do produto
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF);
	prod.productId++;

	// Grava a nova entrada do produto no arquivo
    fprintf(file, PRODUCT_FORMAT_OUT, prod.productId, nameProd, priceProd, maxQuantityProd, quantityProd);
}

void deleteProd(FILE* file, int idProd)
{
    Product prod;

	char check;
    int lineToRemove = 1;

    rewind(file);	// Move o cursor para o inicio do arquivo

	// Procura o produto com o ID especificado
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF && prod.productId != idProd)
    {
        ++lineToRemove;
    }

	system("cls");

    if (prod.productId == idProd)   // Verifica se o produto com o ID especificado foi encontrado
    {
        // Solicita confirmação ao usuário
        printf("Are you sure you want to DELETE %s (Product ID: %d) from the product list? Y/N: ", prod.productName, prod.productId);
        scanf_s(" %c", &check, 1);

        switch (check)
        {
        case 'y':
        case 'Y':
            // Exclusão confirmada pelo usuário, executa a exclusão
            removeLineFromFile(file, lineToRemove);
            printf("Product deleted successfully!");
            Sleep(800);
            break;
        case 'n':
        case 'N':
            // O usuário optou por não excluir, informa e aborta
            system("cls");
            printf("Operation aborted!\n");
            Sleep(800);
            break;
        default:
            // Entrada inválida do usuário
            printf("Invalid Operation!\n");
            Sleep(800);
            break;
        }
    }
    else
    {
        // Produto com o ID especificado não encontrado
        printf("Product with ID %d not found!\n", idProd);
        Sleep(800);
    }
}

void addRmvProd(FILE* file, int idProd)
{
    Product prod;

    char check;
    int amount;

    rewind(file);   // Move o cursor para o inicio do arquivo

    // Procura o produto com o ID especificado
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF && prod.productId != idProd);

    if (prod.productId == idProd)   // Verifica se o produto com o ID especificado foi encontrado
    {
        // Imprime os detalhes do produto encontrado
        printf(PRODUCT_FORMAT_OUT, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);

        // Solicita ao usuário a operação desejada
        printf("Enter desired operation to be performed\nA: to add\nR: to remove\nQ: to abort\nOption: ");
        scanf_s(" %c", &check, 1);

        switch (check)
        {
        case 'a':
        case 'A':
            // Solicita ao usuário que insira o valor a ser adicionado
            printf("Enter desired amount to add: ");
            scanf_s(" %d", &amount);

            // Verifica se adicionar a quantidade especificada excederá a quantidade máxima
            if (prod.productQuantity + amount > prod.productMaxQuantity)
            {
                printf("Invalid amount! Product quantity will be bigger than product max quantity!");
                Sleep(1200);
                break;
            }
            // Chama a função addProd para realizar a adição
            addProd(file, idProd, amount);
            break;
        case 'r':
        case 'R':
            // Solicita ao usuário que insira o valor a ser removido
            printf("Enter desired amount to remove: ");
            scanf_s(" %d", &amount);

            // Verifica se a remoção da quantidade especificada resultará em uma quantidade negativa
            if (prod.productQuantity - amount < 0)
            {
                printf("Invalid amount! Product quantity will be negative!");
                Sleep(1200);
                break;
            }
            // Call the rmvProd function to perform the removal
            rmvProd(file, idProd, amount);
            break;
        case 'q':
        case 'Q':
            // Aborta a operação
            printf("Operation aborted!");
            Sleep(800);
            break;
        default:
            // Operação inválida inserida
            printf("Invalid operation!");
            Sleep(1000);
            break;
        }
    }
    else
    {
        // Produto com o ID especificado não encontrado
        printf("Product with ID %d not found!\n", idProd);
        Sleep(800);
    }
}

void checkProd(FILE* file, int idProd)
{
    Product prod;

    rewind(file);	// Move o cursor para o inicio do arquivo

    // Procura o produto com o ID especificado
    while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF && prod.productId != idProd);

    if (prod.productId == idProd)   // Verifica se o produto com o ID especificado foi encontrado
    {
        // Exibe informações sobre o produto encontrado
        printf(PRODUCT_FORMAT_OUT, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);
        if (prod.productQuantity < prod.productMaxQuantity * 0.37)
        {
            printf("The amount of %s is less than 37%% in stock!\nRestock recommended.", prod.productName);
        }
    }
    else
    {
        // Produto com o ID especificado não encontrado
        printf("Product with ID %d not found!\n", idProd);
        Sleep(800);
    }
}

void listOfProd(FILE* file)
{
    Product prod;

    rewind(file);	// Move o cursor para o inicio do arquivo

    // Le e imprime cada entrada de produto até o final do arquivo
	while (fscanf_s(file, PRODUCT_FORMAT_IN, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF)
	{
		printf(PRODUCT_FORMAT_OUT, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);	// Imprime os detalhes do produto da itereção atual
	}
}
