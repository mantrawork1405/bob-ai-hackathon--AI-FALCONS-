#include <stdio.h>
#include <string.h>

#define MAX 50

struct Vessel {
    char name[50];
    int arrivalTime;
    int containers;
    int berth;
    int crane;
    int priority;
};

void predictCongestion(struct Vessel v[], int n)
{
    int totalContainers = 0;

    for (int i = 0; i < n; i++)
        totalContainers += v[i].containers;

    printf("\n===== CONGESTION PREDICTION =====\n");

    if (totalContainers > 1000)
        printf("WARNING: High congestion predicted!\n");
    else if (totalContainers > 500)
        printf("Moderate congestion predicted.\n");
    else
        printf("Low congestion predicted.\n");

    printf("Total containers: %d\n", totalContainers);
}

void optimizeBerths(struct Vessel v[], int n)
{
    printf("\n===== BERTH ASSIGNMENT =====\n");

    for (int i = 0; i < n; i++)
    {
        v[i].berth = (i % 3) + 1;
        printf("%s -> Berth %d\n", v[i].name, v[i].berth);
    }
}

void assignCranes(struct Vessel v[], int n)
{
    printf("\n===== CRANE ASSIGNMENT =====\n");

    for (int i = 0; i < n; i++)
    {
        if (v[i].containers > 400)
            v[i].crane = 3;
        else if (v[i].containers > 200)
            v[i].crane = 2;
        else
            v[i].crane = 1;

        printf("%s -> %d crane(s)\n",
               v[i].name, v[i].crane);
    }
}

void alternateRoute(struct Vessel v[], int n)
{
    printf("\n===== ALTERNATE ROUTING =====\n");

    for (int i = 0; i < n; i++)
    {
        if (v[i].containers > 400)
            printf("%s -> Use alternate route\n", v[i].name);
        else
            printf("%s -> Normal route\n", v[i].name);
    }
}

void operationsPlan(struct Vessel v[], int n)
{
    printf("\n===== 72-HOUR PORT OPERATIONS PLAN =====\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nVessel: %s", v[i].name);
        printf("\nContainers: %d", v[i].containers);
        printf("\nBerth: %d", v[i].berth);
        printf("\nCranes: %d", v[i].crane);
        printf("\n-------------------------\n");
    }
}

int main()
{
    struct Vessel vessels[MAX];
    int n;

    printf("===== PORT OPERATIONS OPTIMIZER =====\n");

    printf("Enter number of vessels: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for Vessel %d\n", i + 1);

        printf("Vessel name: ");
        scanf("%s", vessels[i].name);

        printf("Arrival time (hour): ");
        scanf("%d", &vessels[i].arrivalTime);

        printf("Number of containers: ");
        scanf("%d", &vessels[i].containers);

        vessels[i].priority = 0;
    }

    predictCongestion(vessels, n);

    alternateRoute(vessels, n);

    optimizeBerths(vessels, n);

    assignCranes(vessels, n);

    operationsPlan(vessels, n);

    printf("\n===== SYSTEM COMPLETED =====\n");

    return 0;
}
