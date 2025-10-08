#include <stdio.h>
#define PRODUCTS 12

struct product {
    unsigned int article;
    float price;
    char* name;
};

// To make binary search working, it needs sorted array!
struct product*
find_product(struct product* prs, unsigned int article) 
{
    int low = 0;
    int high = PRODUCTS - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        struct product p = prs[mid];

        if (p.article == article)
            return &prs[mid];

        if (p.article < article)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return NULL;
}

void
print_product(struct product* p) 
{
    printf("%u: \"%s\" - %.02f \n", p->article, p->name, p->price);
}

int 
main()
{
    // I dont want to make a huge user input again. 
    // Please, i hope hardcoded tests are ok.


    // I could do previous two exercices with structs as well
    struct product prs[PRODUCTS] = {
        {10, 100.000, "Milk"},
        {11, 100.000, "Tabacoo"},
        {12, 100.000, "Coffe"},
        {13, 100.000, "Flower"},
        {17, 100.000, "Crab"},
        {20, 100.000, "Knife"},
        {31, 100.000, "Milk"},
        {43, 100.000, "Lamb"},
        {65, 100.000, "Spoon"},
        {76, 100.000, "Cat"},
        {80, 100.000, "Milk"},
        {90, 100.000, "Milk"},
    };

    char cmd;

    printf("f - find by article \n");
    printf("l - list all products \n");
    printf("0 - exit \n");

    while ( (cmd = getchar()) != EOF ) {
        unsigned int artc;
        struct product* p;

        switch (cmd) {
            case 'f':
                printf("Enter article: ");
                if (scanf("%u", &artc) != 1)
                    printf("\nInvalid article.\n");

                p = find_product(prs, artc);

                if (!p)
                    printf("No such product.\n");
                else
                    print_product(p);

                break;

            case 'l':
                for (int i = 0; i < PRODUCTS; i++)
                    print_product(&prs[i]);
                break;

            case '0': return 0;
            default: break;
        }

    }

    return 0;
}