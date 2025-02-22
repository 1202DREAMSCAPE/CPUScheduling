#include<stdio.h>

//CEREZO, CATUGAS, PASCUAL

int main() {

    int n;
    printf("\n\nEnter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], wt[n], processes[n], priority[n];
    printf("Enter burst time and priority for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &burst_time[i], &priority[i]);
        processes[i] = i+1;
    }

    wt[0] = 0;

//Sort processes based on remaining burst time
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(priority[i] > priority[j]) {

                //swap the priorities of the current process and the next process
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                //swap the burst times of the current process and the next process
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                //swap the process nums of the current process and the next process
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        wt[i] = burst_time[i-1] + wt[i-1];
    }

    int total_wt = 0;
    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
    }
    float avg_wt = (float)total_wt / n;

    printf("\nProcesses  " " Burst time  " " Waiting time  " " Priority\n");
    for(int i = 0; i < n; i++) {
        printf("   %d\t\t%d\t    %d\t\t%d\n", processes[i], burst_time[i], wt[i], priority[i]);
    }
    printf("Average waiting time = %.2f", avg_wt);

    return 0;
}
