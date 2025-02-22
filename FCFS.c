#include<stdio.h>

//CEREZO, CATUGAS, PASCUAL

int main() {

    int n;
    printf("\n\nEnter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], wt[n];
    printf("Enter burst time for each process:\n");

    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    // Initialize waiting time for process 1 and 0
    wt[0] = 0;

    // Calculate waiting time for other processes
    for(int i = 2; i <=n; i++) {
        wt[i] = burst_time[i-1] + wt[i-1];
    }

    // Calculate total waiting time and average waiting time
    int total_wt = 0;
    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
    }
    float avg_wt = (float)total_wt / n;

    // Display waiting time for each process and average waiting time
    printf("\nProcesses  " " Burst time  " " Waiting time\n");
    for(int i = 0; i < n; i++) {
        printf("   %d\t\t%d\t    %d\n", i+1, burst_time[i], wt[i]);
    }
    printf("Average waiting time = %.2f", avg_wt);

    return 0;
}
