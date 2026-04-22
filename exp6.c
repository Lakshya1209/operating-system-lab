#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n], pr[n];
    float total_wt = 0, total_tat = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);

        printf("Enter priority of process %d: ", i+1);
        scanf("%d", &pr[i]);

        p[i] = i + 1;
    }

    // Sort by priority (lower number = higher priority)
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(pr[j] > pr[j+1]) {

                // swap priority
                int temp = pr[j];
                pr[j] = pr[j+1];
                pr[j+1] = temp;

                // swap burst time
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                // swap process id
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // First process
    wt[0] = 0;

    // Waiting time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Table
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    // Averages
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    // Gantt Chart
    printf("\nGantt Chart:\n");

    for(i = 0; i < n; i++) printf("--------");
    printf("\n|");

    for(i = 0; i < n; i++) printf("  P%d   |", p[i]);

    printf("\n");
    for(i = 0; i < n; i++) printf("--------");

    printf("\n0");

    int time = 0;
    for(i = 0; i < n; i++) {
        time += bt[i];
        printf("      %d", time);
    }

    printf("\n");

    return 0;
}