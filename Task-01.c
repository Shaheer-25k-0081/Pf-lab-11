#include <stdio.h>

struct gift
{
    char name[20];
    char type[20];
    float price;
    int quantity;
};

int main() {
    int n;
    printf("Enter how many gifts are there: ");
    scanf(" %d", &n);

    struct gift gifts[n];

    for (int i = 0; i < n; i++)
    {   
        printf("-----Gift#%d-----\n", i+1);
        printf("Enter the name for gift: ");
        scanf("%s", gifts[i].name);

        printf("Enter the type for gift: ");
        scanf("%s", gifts[i].type);

        printf("Enter the price for gift: ");
        scanf(" %f", &gifts[i].price);

        printf("Enter the quantity for gift: ");
        scanf(" %d", &gifts[i].quantity);
    }
    
    float max_price = 0;
    int max_price_index = 0;
    int max_quantity = 0;
    int max_quantity_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (gifts[i].price > max_price)
        {
            max_price = gifts[i].price;
            max_price_index = i + 1;
        }

        if (gifts[i].quantity > max_quantity)
        {
            max_quantity = gifts[i].quantity;
            max_quantity_index = i + 1;
        }
    }
    printf("-----------------------\n");
    printf("Gift %d is the most expensive gift.\n", max_price_index);
    printf("Gift %d is available in large quantities.\n", max_quantity_index);

    return 0;
}