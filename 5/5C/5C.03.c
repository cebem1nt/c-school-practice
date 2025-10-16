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
    struct product prs[PRODUCTS] = {
        {10, 100.000, "Milk"},
        {11, 100.000, "Tabacoo"},
        {12, 100.000, "Coffe"},
        {20, 100.000, "Knife"},
        {21, 100.000, "Milk"},
        {30, 100.000, "Milk"},
        {40, 100.000, "Milk"},
        {57, 100.000, "Crab"},
        {65, 100.000, "Spoon"},
        {73, 100.000, "Lamb"},
        {83, 100.000, "Flower"},
        {96, 100.000, "Cat"},
    };

    printf("f - find by article \n");
    printf("l - list all products \n");
    printf("0 - exit \n");

    while (1) {
        struct product* p;
        int artc;
        char cmd[1];

        if (scanf("%s", cmd) != 1) {
            fprintf(stderr, "Invalid command, try again.\n");
            continue;
        }

        switch (cmd[0]) {
        case 'f':
            printf("Enter article: ");
            if (scanf("%u", &artc) != 1) {
                fprintf(stderr, "Invalid article \n");
                break;
            }

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