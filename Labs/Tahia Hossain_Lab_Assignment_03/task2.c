#include <stdio.h>
#include <stdbool.h>

#define N 4 

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calc_rr(Process processes[], int quantum) {
    int time = 0;
    int processes_left = N;
    bool is_completed[N] = {false}; 
    for (int i = 0; i < N; ++i) {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i+1;
        processes[i].waiting_time = 0; 
    }

    while (processes_left > 0) {
        for (int i = 0; i < N; ++i) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                    // Update waiting time for other processes
                    for (int j = 0; j < N; ++j) {
                        if (j != i && processes[j].remaining_time > 0) {
                            processes[j].waiting_time += quantum;
                        }
                    }
                } else {
                    time += processes[i].remaining_time;
                    // Update waiting time for other processes
                    for (int j = 0; j < N; ++j) {
                        if (j != i && processes[j].remaining_time > 0) {
                            processes[j].waiting_time += processes[i].remaining_time;
                        }
                    }
                    processes[i].remaining_time = 0;
                    processes[i].completion_time = time;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    is_completed[i] = true;
                    processes_left--;
                }
            }
        }
    }
}

int main() {
    Process processes[N];
    int quantum;
    FILE *file = fopen("input2.txt", "r");
    fscanf(file, "%d", &quantum);
    for (int i = 0; i < N; ++i) {
        processes[i].pid = i + 1; 
        fscanf(file, "%d", &processes[i].burst_time);
    }
    fclose(file); 

    calc_rr(processes, quantum);

    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < N; ++i) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < N; ++i) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",
               processes[i].pid,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time,
               processes[i].completion_time);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time / N);
    printf("Average Turnaround Time = %.2f\n", total_turnaround_time / N);
    
    return 0;
}