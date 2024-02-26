#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

int compare(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    if (p1->arrival_time == p2->arrival_time) {
        return p1->priority - p2->priority;
    }
    return p1->arrival_time - p2->arrival_time;
}

void calculate_priority(Process processes[], int n) {
    int time = 0; 
    int executed = 0;

    qsort(processes, n, sizeof(Process), compare);

    while (executed < n) {
        int index = -1;
        int high_priority = __INT_MAX__;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (processes[i].priority < high_priority || (processes[i].priority == high_priority && processes[i].arrival_time < processes[index].arrival_time)) {
                    high_priority = processes[i].priority;
                    index = i;
                }
            }
        }
        if (index == -1) {
            time++;
        } else {
            processes[index].remaining_time--;
            if (processes[index].remaining_time == 0) {
                processes[index].completion_time = time + 1;
                processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
                processes[index].waiting_time = processes[index].turnaround_time - processes[index].burst_time;
                executed++;
            }
            time++;
        }
    }
}

int main() {
    FILE *file = fopen("input3.txt", "r");
    
    int N;
    fscanf(file, "%d", &N);
    Process *processes = malloc(N * sizeof(Process));

    for (int i = 0; i < N; ++i) {
        fscanf(file, "%d %d %d %d",
               &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
    }

    fclose(file);

    calculate_priority(processes, N); 

    float total_waiting_time = 0, total_turn_time = 0;
    for (int i = 0; i < N; ++i) {
        total_waiting_time += processes[i].waiting_time;
        total_turn_time += processes[i].turnaround_time;
    }

    printf("Process ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < N; ++i) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].priority,
               processes[i].waiting_time,
               processes[i].turnaround_time,
               processes[i].completion_time);
    }
    
    printf("\nAverage Waiting Time = %.1f\n", total_waiting_time / N);
    printf("Average Turnaround Time = %.1f\n", total_turn_time / N);
    free(processes); 
    return 0;
}