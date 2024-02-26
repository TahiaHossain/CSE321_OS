#include <stdio.h>
#include <stdbool.h>

#define n 5 
#define m 4 

int alloc[n][m] = { {0, 1, 0, 3}, // P0 
                    {2, 0, 0, 0}, // P1
                    {3, 0, 2, 0}, // P2
                    {2, 1, 1, 5}, // P3
                    {0, 0, 2, 2}  // P4
};

int max[n][m] = {   {6, 4, 3, 4}, // P0 
                    {3, 2, 2, 1}, // P1
                    {9, 1, 2, 6}, // P2
                    {2, 2, 2, 8}, // P3
                    {4, 3, 3, 7}  // P4
};

int avail[m] = {3, 3, 2, 1}; 

bool safe(int process, int resources[], bool end[]) {
    for (int i = 0; i < m; ++i) 
    {
        if (max[process][i] - alloc[process][i] > resources[i])
            return false;
    }
    return true;
}

int main()
{
    int resources[m];
    bool end[n];

    for (int i = 0; i < m; ++i) {
        resources[i] = avail[i];
    }
    for (int i = 0; i < n; ++i) {
        end[i] = false;
    }

    int safeSeq[n];
    int count = 0;

    while (count < n) { // Find safe seq
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!end[i] && safe(i, resources, end)) {
                // Allocate resources to the process
                for (int j = 0; j < m; ++j) {
                    resources[j] += alloc[i][j];
                }
                end[i] = true;
                safeSeq[count++] = i;
                found = true;
                break;
            }
        }
        if (!found)
        {
            printf("Deadlock Ahead\n");
            return 0;
        }
    }
    printf("Safe here\n");
    return 0;
}