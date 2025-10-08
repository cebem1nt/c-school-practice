#include <stdio.h>

#define PRODUCTS 12

struct product {
    unsigned int article;
    float price;
    char* name;
};

struct product*
find_product(struct product* prs, unsigned int article) 
{
    for (int i = 0; i < PRODUCTS; i++) 
    {
        if (prs[i].article == article) {
            return &prs[i];
        }
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
        {20, 100.000, "Knife"},
        {31, 100.000, "Milk"},
        {12, 100.000, "Coffe"},
        {11, 100.000, "Tabacoo"},
        {80, 100.000, "Milk"},
        {90, 100.000, "Milk"},
        {17, 100.000, "Crab"},
        {65, 100.000, "Spoon"},
        {43, 100.000, "Lamb"},
        {13, 100.000, "Flower"},
        {76, 100.000, "Cat"},
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

        case '0':
            return 0;
        
        default:
            break;
        }

    }

    return 0;
}