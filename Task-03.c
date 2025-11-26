#include <stdio.h>


struct Employee
{
    char name[20];
    int ID;
    int days_present;
};

int calcAttendance(struct Employee arr[], int index, int size, int total) {
    if (index >= size)
    {
        return total;
    }

    total += arr[index].days_present;
    calcAttendance(arr, index + 1, size, total);
}

int main() {
    int n;
    printf("How many employees are there: ");
    scanf(" %d", &n);

    struct Employee data[n];

    for (int i = 0; i < n; i++)
    {
        printf("-----Employee # %d-----\n", i+1);

        printf("Enter name: ");
        scanf("%s", data[i].name);

        printf("Enter ID: ");
        scanf(" %d", &data[i].ID);

        printf("Enter number of days present: ");
        scanf(" %d", &data[i].days_present);
    }
    
    int total = calcAttendance(data, 0, n, 0);
    printf("Total Attendance: %d\n", total);
    return 0;
}