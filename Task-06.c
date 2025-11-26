#include <stdio.h>
#include <string.h>

struct Item {
    char name[50];
    char category[50];
    int quantity;
};

void findItems(struct Item *inventory, int size, char *category, int minQuantity) {
    struct Item *ptr = inventory;
    
    for (int i = 0; i < size; i++) {
        if (strcmp(ptr->category, category) == 0 && ptr->quantity >= minQuantity) {
            printf("Name: %s, Category: %s, Quantity: %d\n", ptr->name, ptr->category, ptr->quantity);
        }
        ptr++;
    }
}

int main() {
    struct Item inventory[100];
    int itemCount;
    
    printf("Enter number of items: ");
    scanf("%d", &itemCount);
    
    for (int i = 0; i < itemCount; i++) {
        printf("Enter item name: ");
        scanf("%s", inventory[i].name);
        printf("Enter category: ");
        scanf("%s", inventory[i].category);
        printf("Enter quantity: ");
        scanf("%d", &inventory[i].quantity);
    }
    
    char searchCategory[50];
    int minQty;
    
    printf("Enter category to search: ");
    scanf("%s", searchCategory);
    printf("Enter minimum quantity: ");
    scanf("%d", &minQty);
    
    findItems(inventory, itemCount, searchCategory, minQty);
    
    return 0;
}