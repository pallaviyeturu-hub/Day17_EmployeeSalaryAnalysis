#include <stdio.h>

int main() {
    char name[50], reg[30], section[10];
    int n, i, choice;
    int salaries[10];
    int total, highest, lowest;
    float avg;

    printf("======== Employee Salary Analysis System ========\n");

    printf("Enter Student Name: ");
    scanf("%[^\n]", name);
    getchar();

    printf("Enter Registration Number: ");
    scanf("%s", reg);

    printf("Enter Section: ");
    scanf("%s", section);

    printf("Enter number of employees: ");
    scanf("%d", &n);

    printf("Enter salaries:\n");
    for (i = 1; i <= n; i++) {
        printf("%d: ", i);
        scanf("%d", &salaries[i]);
    }

    while (1) {
        printf("\n======== Menu =========\n");
        printf("1. Display All Salaries\n");
        printf("2. Display Total and Average Salary\n");
        printf("3. Display Highest and Lowest Salary\n");
        printf("4. Count Above/Below Average\n");
        printf("5. Display Sorted Salaries\n");
        printf("6. Exit\n");
        printf("=======================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            for (i = 1; i <= n; i++)
                printf("%d ", salaries[i]);
            printf("\n");
        }

        else if (choice == 2) {
            total = 0;
            for (i = 1; i <= n; i++) total += salaries[i];
            avg = total / (float)n;

            printf("Total Salary = %d\n", total);
            printf("Average Salary = %.0f\n", avg);
        }

        else if (choice == 3) {
            highest = salaries[1];
            lowest = salaries[1];
            for (i = 2; i <= n; i++) {
                if (salaries[i] > highest) highest = salaries[i];
                if (salaries[i] < lowest) lowest = salaries[i];
            }
            printf("Highest Salary = %d\n", highest);
            printf("Lowest Salary = %d\n", lowest);
        }

        else if (choice == 4) {
            total = 0;
            for (i = 1; i <= n; i++) total += salaries[i];
            avg = total / n;

            int above = 0, below = 0;
            for (i = 1; i <= n; i++) {
                if (salaries[i] > avg) above++;
                else if (salaries[i] < avg) below++;
            }

            printf("Above Avg = %d, Below Avg = %d\n", above, below);
        }

        else if (choice == 5) {
            for (int a = 1; a <= n - 1; a++) {
                for (int b = 1; b <= n - a; b++) {
                    if (salaries[b] > salaries[b+1]) {
                        int t = salaries[b];
                        salaries[b] = salaries[b+1];
                        salaries[b+1] = t;
                    }
                }
            }

            for (i = 1; i <= n; i++)
                printf("%d ", salaries[i]);
            printf("\n");
        }

        else if (choice == 6) {
            break;
        }
    }

    printf("\nSubmitted by: %s | Reg No: %s | Section: %s\n", name, reg, section);
    printf("Challenge Day 17 - Code2Grow Program\n");

    return 0;
}