cpushed.c
#include<stdio.h>
#include<stdlib.h>
int fcfs()
{
 int n, i;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], wait_time[n], turnaround_time[n];
    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    wait_time[0] = 0;
    for (i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
    }
    for (i = 0; i < n; i++) {
        turnaround_time[i] = wait_time[i] + burst_time[i];
    }
    for (i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    return 0;
}
int sjf() {
    int n, i, j, temp;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], wait_time[n], turnaround_time[n];
    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }
    wait_time[0] = 0;
    for (i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
    }
    for (i = 0; i < n; i++) {
        turnaround_time[i] = wait_time[i] + burst_time[i];
    }
    for (i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    return 0;
}
int non_pre() {
    int n, i, j, max_priority_index,temp;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], wait_time[n], turnaround_time[n], priority[n];
    printf("Enter the burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d %d", &burst_time[i], &priority[i]);
    }
    for (i = 0; i < n - 1; i++) {
        max_priority_index = i;
        for (j = i + 1; j < n; j++) {
            if (priority[j] > priority[max_priority_index]) {
                max_priority_index = j;
            }
        }
        temp = burst_time[i];
        burst_time[i] = burst_time[max_priority_index];
        burst_time[max_priority_index] = temp;
        temp = priority[i];
        priority[i] = priority[max_priority_index];
        priority[max_priority_index] = temp;
    }
    wait_time[0] = 0;
    for (i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
    }
    for (i = 0; i < n; i++) {
        turnaround_time[i] = wait_time[i] + burst_time[i];
    }
    for (i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], priority[i], wait_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    return 0;
}
int rr() {
    int n, i, j, time = 0, remaining_time, quantum;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], wait_time[n], turnaround_time[n], remaining_burst_time[n];
    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_burst_time[i] = burst_time[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                done = 0;
                if (remaining_burst_time[i] > quantum) {
                    remaining_burst_time[i] -= quantum;
                    time += quantum;
                } else {
                    time += remaining_burst_time[i];
                    wait_time[i] = time - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + wait_time[i];
    }
    for (i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    return 0;
}
int main()
{
int i=1;
while(i!=0)
{
int cho;
printf("1.FCFS\n2.SJF\n3.Non Preemtive\n4.Round Robing\n5.Exit\nEnter your choice:\n");
scanf("%d",&cho);
switch(cho)
{
case 1:
fcfs();
break;
case 2:
sjf();
break;
case 3:
non_pre();
break;
case 4:
rr();
break;
case 5:
printf("Exiting...");
i=0;
exit(0);
break;
}
}
}
