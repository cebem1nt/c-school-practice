#include <stdio.h>
#include <stdlib.h>

const int items = 6;
const int name_len = 256;

void 
get_code(int codes[items], int index)
{
    printf("Enter code for item %d: ", index + 1);
    if (scanf("%d", &codes[index]) != 1) {
        exit(1);
    }
}

void 
get_name(char names[items][name_len], int index)
{
    printf("Enter name for item %d: ", index + 1);
    if (scanf("%255s", names[index]) != 1) {
        exit(1);
    }
}

void 
get_price(float prices[items], int index)
{
    printf("Enter price for item %d: ", index + 1);
    if (scanf("%f", &prices[index]) != 1) {
        exit(1);
    }
}

float 
average_price(float prices[items])
{
    float sum = 0.0f;
    for (int i = 0; i < items; i++) {
        sum += prices[i];
    }
    return sum / items;
}

int main(void)
{
    int codes[items];
    char names[items][name_len];
    float prices[items];

    for (int i = 0; i < items; i++) {
        get_code(codes, i);
        get_name(names, i);
        get_price(prices, i);
    }

    float avg = average_price(prices);

    int count_code_gt3_price_lt5 = 0;
    int min_code_index = 0;
    int min_price_index = 0;

    for (int i = 1; i < items; i++) {
        if (codes[i] < codes[min_code_index]) {
            min_code_index = i;
        }
        if (prices[i] < prices[min_price_index]) {
            min_price_index = i;
        }
        if (codes[i] > 3 && prices[i] < 5.0f) {
            count_code_gt3_price_lt5++;
        }
    }

    if (codes[0] > 3 && prices[0] < 5.0f) {
        count_code_gt3_price_lt5++;
    }

    float percent_condition = ((float)count_code_gt3_price_lt5 / items) * 100.0f;

    printf("a) Average price: %.2f\n", avg);
    printf("b) Percentage of items with code > 3 and price < 5: %.2f%%\n", percent_condition);
    printf("c) Smallest code (unique): %d\n", codes[min_code_index]);
    printf("d) Name of item with smallest price (unique): %s\n", names[min_price_index]);

    printf("\n e) items with code between 2 and 7 (inclusive):\n");
    int found = 0;
    for (int i = 0; i < items; i++) {
        if (codes[i] >= 2 && codes[i] <= 7) {
            printf("   Code: %d | Name: %s | Price: %.2f\n", codes[i], names[i], prices[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("   (none)\n");
    }

    printf("\nFull list of items:\n");
    for (int i = 0; i < items; i++) {
        printf(" Item %d -> Code: %d ; Name: %s ; Price: %.2f\n", i + 1, codes[i], names[i], prices[i]);
    }

    return 0;
}