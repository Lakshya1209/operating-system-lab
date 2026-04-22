#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    // Input Burst Time
    for(i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // First process waiting time = 0
    wt[0] = 0;

    // Calculate Waiting Time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display Table
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    // Calculate and display averages
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    // Gantt Chart
    printf("\nGantt Chart:\n");

    // Top bar
    for(i = 0; i < n; i++) {
        printf("--------");
    }
    printf("\n|");

    // Process IDs
    for(i = 0; i < n; i++) {
        printf("  P%d   |", i+1);
    }

    printf("\n");

    // Bottom bar
    for(i = 0; i < n; i++) {
        printf("--------");
    }
    printf("\n");

    // Time values
    printf("0");
    for(i = 0; i < n; i++) {
        printf("      %d", wt[i] + bt[i]);
    }

    printf("\n");

    return 0;
}