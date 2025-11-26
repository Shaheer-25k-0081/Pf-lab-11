#include <stdio.h>
#include <string.h>

struct word
{
    char check[100];
};

void reverseWord(char arr[], int start, int end) {
    if (start > end)
    {
        return;
    }
    char temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseWord(arr, start + 1, end - 1);
}

int main() {
    int n;

    printf("How many words do you want to check: ");
    scanf(" %d", &n);

    struct word words[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the word: ");
        scanf("%s", words[i].check);

        char original[100];
        strcpy(original, words[i].check);

        int start = 0;
        int end = strlen(words[i].check) - 1;
        reverseWord(words[i].check, start, end);

        printf("Reversed Word: %s\n", words[i].check);

        if (strcmp(words[i].check, original) == 0)
        {
            printf("This word is a palidrome!");
        }
        else
        {
            printf("This word is not a palindrome!");
        }
        
        printf("\n-------------------------\n");
    }
    return 0;
}