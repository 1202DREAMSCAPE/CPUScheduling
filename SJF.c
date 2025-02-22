#include<stdio.h>

//CEREZO, CATUGAS, PASCUAL

int main() {

    int n;
    printf("\n\nEnter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], wt[n], processes[n];
    printf("Enter burst time for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        processes[i] = i+1;
    }

    // Initialize the waiting time for process 1 as 0
    wt[0] = 0;

//Sort processes based on remaining burst time
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(burst_time[i] > burst_time[j]) {
            // swap burst times of the current and the next para ascending    
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            // swap process times of the current and the next para ascending
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

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
        printf("   %d\t\t%d\t    %d\n", processes[i], burst_time[i], wt[i]);
    }
    printf("Average waiting time = %.2f", avg_wt);

    return 0;
}
