#include "action.h"
#include "product.h"

const char* PRODUCT_FORMAT_INP = "Id: %d, Name: %[^,], Price: $%f, Max Quantity: %d, Quantity: %d\n";	// String para um formato de entrada para leitura de detalhes do produto em um arquivo
const char* PRODUCT_FORMAT_OUTP = "Id: %5d, Name: %25s, Price: $%8.2f, Max Quantity: %4d, Quantity: %4d\n";    // String para um formato de saida para impressao de detalhes do produto de um arquivo

void removeLineFromFile(FILE* file, int lineToRemove)
{
    // Cria um arquivo temporário
    FILE* tempFile;
    tmpfile_s(&tempFile);
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        return;
    }

    int currentLine = 1;
    char buffer[1024];    // Cria um buffer para salvar as informações

    rewind(file);   // Volta o cursor até o inicio do arquivo

    while (fgets(buffer, sizeof(buffer), file) != NULL)     // Obtem todas as informações salvas em um buffer
    {
        // Verifica se currentLine não é a linha desejada para remover
        if (currentLine != lineToRemove)
        {
            fputs(buffer, tempFile);    // Salva informações do buffer em tempFile
        }

        currentLine++;
    }

    rewind(tempFile);   // Volta o cursor até o inicio do arquivo temporario

    rewind(file);   // Volta o cursor até o inicio do arquivo

    freopen_s(&file, "product.txt", "w", file);     // Exclui todo conteúdo do arquivo sobrescrevendo ele

    freopen_s(&file, "product.txt", "r+", file);    // Reabre arquivo em modo leitura/gravação

    while (fgets(buffer, sizeof(buffer), tempFile) != NULL)     // Grava todos os dados salvos em tempFile no arquivo
    {
        fputs(buffer, file);
    }

    remove("temp.txt");

    fclose(tempFile);   // Fecha o arquivo temporário
}

void addProd(FILE* file, int idProd, int amount)
{
    // Cria um arquivo temporário
    FILE* tempFile;
    tmpfile_s(&tempFile);
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        return;
    }

    Product prod;

    char buffer[1024];    // Cria um buffer para salvar as informações
    int id = 0;

    // Volta o cursor até o inicio do arquivo
    rewind(file);

    // Le cada linha do arquivo original
    while (fscanf_s(file, PRODUCT_FORMAT_INP, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF)
    {
        if (prod.productId == idProd)    // Encontra o produto para atualizar
        {            
            prod.productQuantity += amount;
            id = prod.productId;
        }

        // Grava a linha modificada ou não modificada no arquivo temporário
        fprintf(tempFile, PRODUCT_FORMAT_OUTP, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);
    }

    rewind(tempFile);   // Volta o cursor até o inicio do arquivo temporario

    rewind(file);   // Volta o cursor até o inicio do arquivo

    freopen_s(&file, "product.txt", "w", file);     // Exclui todo conteúdo do arquivo sobrescrevendo ele

    freopen_s(&file, "product.txt", "r+", file);    // Reabre arquivo em modo leitura/gravação

    while (fgets(buffer, sizeof(buffer), tempFile) != NULL)     // Grava todos os dados salvos em tempFile no arquivo
    {
        fputs(buffer, file);
    }

    remove("temp.txt");

    fclose(tempFile);   // Fecha o arquivo temporario

    printf("Amount successfuly added to ID %d", id);
    Sleep(800);
}

void rmvProd(FILE* file, int idProd, int amount)
{
    // Cria um arquivo temporario
    FILE* tempFile;
    tmpfile_s(&tempFile);
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        return;
    }

    Product prod;

    char buffer[1024];
    int id = 0;

    // Voltar o cursor até o inicio do arquivo
    rewind(file);

    // Le cada linha do arquivo original
    while (fscanf_s(file, PRODUCT_FORMAT_INP, &prod.productId, prod.productName, 50, &prod.productPrice, &prod.productMaxQuantity, &prod.productQuantity) != EOF)
    {
        if (prod.productId == idProd)    // Encontra o produto para atualizar
        {
            prod.productQuantity -= amount;
            id = prod.productId;
        }

        // Grava a linha modificada ou não modificada no arquivo temporário
        fprintf(tempFile, PRODUCT_FORMAT_OUTP, prod.productId, prod.productName, prod.productPrice, prod.productMaxQuantity, prod.productQuantity);
    }

    rewind(tempFile);   // Volta o cursor até o inicio do arquivo temporario

    rewind(file);   // Volta o cursor até o inicio do arquivo

    freopen_s(&file, "product.txt", "w", file);     // Exclui todo conteúdo do arquivo sobrescrevendo ele

    freopen_s(&file, "product.txt", "r+", file);    // Reabre arquivo em modo leitura/gravação

    while (fgets(buffer, sizeof(buffer), tempFile) != NULL)     // Grava todos os dados salvos em tempFile no arquivo
    {
        fputs(buffer, file);
    }

    remove("temp.txt");

    fclose(tempFile);   // Fecha o arquivo temporario

    printf("Amount successfuly removed from ID %d", id);
    Sleep(800);
}
