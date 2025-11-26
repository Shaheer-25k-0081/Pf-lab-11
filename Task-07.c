#include <stdio.h>
#include <string.h>

struct Forecast {
    char color[20];
    int number;
    char advice[100];
};

struct User {
    char name[50];
    int day;
    int month;
    int year;
    char zodiac[20];
    struct Forecast daily;
};

void assignZodiac(struct User *user) {
    int day = user->day;
    int month = user->month;
    
    if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
        strcpy(user->zodiac, "Aries");
    else if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
        strcpy(user->zodiac, "Taurus");
    else if ((month == 5 && day >= 21) || (month == 6 && day <= 20))
        strcpy(user->zodiac, "Gemini");
    else if ((month == 6 && day >= 21) || (month == 7 && day <= 22))
        strcpy(user->zodiac, "Cancer");
    else if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
        strcpy(user->zodiac, "Leo");
    else if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
        strcpy(user->zodiac, "Virgo");
    else if ((month == 9 && day >= 23) || (month == 10 && day <= 22))
        strcpy(user->zodiac, "Libra");
    else if ((month == 10 && day >= 23) || (month == 11 && day <= 21))
        strcpy(user->zodiac, "Scorpio");
    else if ((month == 11 && day >= 22) || (month == 12 && day <= 21))
        strcpy(user->zodiac, "Sagittarius");
    else if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
        strcpy(user->zodiac, "Capricorn");
    else if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
        strcpy(user->zodiac, "Aquarius");
    else
        strcpy(user->zodiac, "Pisces");
}

void updateForecast(struct Forecast forecasts[12], char zodiac[20]) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(forecasts[i].color, zodiac) == 0) {
            printf("Enter lucky color: ");
            scanf("%s", forecasts[i].color);
            printf("Enter lucky number: ");
            scanf("%d", &forecasts[i].number);
            printf("Enter advice: ");
            scanf(" %[^\n]", forecasts[i].advice);
            return;
        }
    }
}

void displayHoroscope(struct User user) {
    printf("\n--- Horoscope for %s ---\n", user.name);
    printf("Zodiac: %s\n", user.zodiac);
    printf("Birthdate: %d/%d/%d\n", user.day, user.month, user.year);
    printf("Lucky Color: %s\n", user.daily.color);
    printf("Lucky Number: %d\n", user.daily.number);
    printf("Advice: %s\n", user.daily.advice);
}

int main() {
    struct User users[50];
    struct Forecast forecasts[12] = {
        {"Aries", 7, "Take risks today"},
        {"Taurus", 4, "Stay grounded"},
        {"Gemini", 3, "Communicate clearly"},
        {"Cancer", 9, "Trust your instincts"},
        {"Leo", 1, "Shine bright"},
        {"Virgo", 6, "Pay attention to details"},
        {"Libra", 2, "Find balance"},
        {"Scorpio", 8, "Be passionate"},
        {"Sagittarius", 5, "Explore new things"},
        {"Capricorn", 10, "Work hard"},
        {"Aquarius", 11, "Think differently"},
        {"Pisces", 12, "Follow your dreams"}
    };
    
    int userCount;
    printf("Enter number of users: ");
    scanf("%d", &userCount);
    
    for (int i = 0; i < userCount; i++) {
        printf("\nUser %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", users[i].name);
        printf("Enter birthdate (dd mm yyyy): ");
        scanf("%d %d %d", &users[i].day, &users[i].month, &users[i].year);
        
        assignZodiac(&users[i]);
        
        for (int j = 0; j < 12; j++) {
            if (strcmp(forecasts[j].color, users[i].zodiac) == 0) {
                users[i].daily = forecasts[j];
                break;
            }
        }
    }
    
    int choice;
    do {
        printf("\n1. Display horoscope\n2. Update forecast\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int userIndex;
            printf("Enter user number (1-%d): ", userCount);
            scanf("%d", &userIndex);
            if (userIndex >= 1 && userIndex <= userCount) {
                displayHoroscope(users[userIndex - 1]);
            }
        } else if (choice == 2) {
            char zodiac[20];
            printf("Enter zodiac to update: ");
            scanf("%s", zodiac);
            updateForecast(forecasts, zodiac);
            
            for (int i = 0; i < userCount; i++) {
                for (int j = 0; j < 12; j++) {
                    if (strcmp(forecasts[j].color, users[i].zodiac) == 0) {
                        users[i].daily = forecasts[j];
                        break;
                    }
                }
            }
        }
    } while (choice != 3);
    
    return 0;
}