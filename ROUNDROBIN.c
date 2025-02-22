#include<stdio.h>

//CEREZO, CATUGAS, PASCUAL

int main() {
   int n, tq, i, j, k, temp, total_wt = 0, total_tat = 0;
   float avg_wt, avg_tat;

   printf("\n\nEnter the number of processes: ");
   scanf("%d", &n);

   int burst_time[n], waiting_time[n], turnaround_time[n];
   printf("Enter the burst time for each process [seperate with a space]: ");
   for(i = 0; i < n; i++) {
       scanf("%d", &burst_time[i]);
   }
   printf("Enter the time quantum: ");
   scanf("%d", &tq);

// Calculate the remaining burst time for each process after each time quantum
   for(i = 0; i < n; i++) {
       for(j = 0; j < burst_time[i]; j += tq) {
           if(burst_time[i] > tq) {
               burst_time[i] -= tq;
           } else {
               burst_time[i] = 0;
           }
       }
   }

  // Sort the processes based on their remaining burst time
  for(i = 0; i < n; i++) {
       for(j = 0; j < n; j++) {
           if(burst_time[j] > burst_time[i]) {
               temp = burst_time[i];
               burst_time[i] = burst_time[j];
               burst_time[j] = temp;
           }
       }
   }

// Calculate the waiting time and turnaround time for each process
   for(i = 0; i < n; i++) {
       for(j = 0; j < n; j++) {
           if(burst_time[j] == burst_time[i]) {
               waiting_time[j] = total_wt;
               total_wt += burst_time[j];
               turnaround_time[j] = burst_time[j] + waiting_time[j];
               total_tat += turnaround_time[j];
           }
       }
   }

   avg_wt = (float)total_wt / n;
   avg_tat = (float)total_tat / n;

   printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time");
   for(i = 0; i < n; i++) {
       printf("\n   %d\t\t %d\t\t %d\t\t %d", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
   }
   printf("\n\nAverage Waiting Time = %.2f", avg_wt);
   printf("\nAverage Turnaround Time = %.2f \n\n", avg_tat);
}
