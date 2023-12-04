#include "arraymngr.h"
#include "product.h"

void paginateProductArray(Product* pProd, int pageSize)
{
    int totalPages = (sizeof(pProd) + pageSize - 1) / pageSize;

    // Loop through each page
    for (int page = 0; page < totalPages; ++page) {
        printf("Page %d:\n", page + 1);

        // Loop through items on the current page
        for (int i = page * pageSize; i < (page + 1) * pageSize && i < sizeof(pProd); ++i) {
            printf("%d ", pProd[i]);
        }

        printf("\n\n");
    }
}