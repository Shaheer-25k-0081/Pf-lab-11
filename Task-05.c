#include <stdio.h>

struct Team {
    char name[50];
    int scores[10];
    int rounds;
};

int calculateTotal(int arr[], int n) {
    if (n <= 0) return 0;
    return calculateTotal(arr, n - 1) + arr[n - 1];
}

void processTeams(struct Team teams[], int numTeams, int threshold) {
    for (int i = 0; i < numTeams; i++) {
        int total = calculateTotal(teams[i].scores, teams[i].rounds);
        printf("Team: %s, Total Score: %d", teams[i].name, total);
        if (total >= threshold) {
            printf(" - ABOVE THRESHOLD");
        }
        printf("\n");
    }
}

int main() {
    struct Team teams[3];
    
    for (int i = 0; i < 3; i++) {
        printf("Enter team name: ");
        scanf("%s", teams[i].name);
        printf("Enter number of rounds: ");
        scanf("%d", &teams[i].rounds);
        printf("Enter scores for %d rounds: ", teams[i].rounds);
        for (int j = 0; j < teams[i].rounds; j++) {
            scanf("%d", &teams[i].scores[j]);
        }
    }
    
    int threshold;
    printf("Enter threshold score: ");
    scanf("%d", &threshold);
    
    processTeams(teams, 3, threshold);
    
    return 0;
}