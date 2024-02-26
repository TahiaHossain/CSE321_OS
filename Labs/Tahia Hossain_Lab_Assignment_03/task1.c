#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5 

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int is_completed;
} Process;

void find_completion(Process processes[]) {
    int current_time = 0;
    int completed = 0;
    int last_pid = -1;

    while (completed < N) {
        int short_time = INT_MAX;
        int pid_index = -1;

        // Find process with the shortest remaining time at current time
        for (int i = 0; i < N; i++) {
            if (processes[i].arrival_time <= current_time && !processes[i].is_completed) {
                if (processes[i].remaining_time < short_time) {
                    short_time = processes[i].remaining_time;
                    pid_index = i;
                }
                if (processes[i].remaining_time == short_time) {
                    if (processes[i].arrival_time < processes[pid_index].arrival_time) {
                        pid_index = i;
                    }
                }
            }
        }

        // If a process is found for execution
        if (pid_index != -1) {
            if (last_pid != pid_index) { // Context switch, for tracking only
                printf("Time %d: P%d\n", current_time, processes[pid_index].pid);
                last_pid = pid_index;
            }
            processes[pid_index].remaining_time--;
            current_time++;
            if (processes[pid_index].remaining_time == 0) {
                processes[pid_index].completion_time = current_time;
                processes[pid_index].is_completed = 1;
                processes[pid_index].turnaround_time = processes[pid_index].completion_time - processes[pid_index].arrival_time;
                processes[pid_index].waiting_time = processes[pid_index].turnaround_time - processes[pid_index].burst_time;
                completed++;
            }
        } else {
            current_time++;
        }
    }
}

int main() {
    Process processes[N];

    FILE *inputFile = fopen("input1.txt", "r");

    // Read input
    for (int i = 0; i < N; i++) {
        if (fscanf(inputFile, "%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time) != 3) {
            printf("Error reading input from the file.\n");
            fclose(inputFile);
            return 1;
        }
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].is_completed = 0;
    }

    fclose(inputFile);

    find_completion(processes);

    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < N; ++i) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Display details
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < N; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time / N);
    printf("Average Turnaround Time = %.2f\n", total_turnaround_time / N);

    return 0;
}