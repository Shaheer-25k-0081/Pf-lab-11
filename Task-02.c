#include <stdio.h>


void printDays(int n) {
    if (n == 0)
    {
        printf("Event Day!\n");
        return;
    }
    
    printf("%d Days Left!\n", n);
    printDays(n-1);
}

struct event
{
    int days_left;
};

int main() {
    int n;
    printf("How many events: ");
    scanf(" %d", &n);

    struct event events[n];

    for (int i = 0; i < n; i++)
    {
        printf("How many days till Event # %d: ", i+1);
        scanf(" %d", &events[i].days_left);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("\n-----Event # %d-----\n", i+1);
        printDays(events[i].days_left);
    }
    return 0;
}