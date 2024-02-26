#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild1_pid, grandchild2_pid, grandchild3_pid;

    child_pid = fork(); 

    if (child_pid == -1) 
    {
        printf("Failed to create child process.\n");
        return 1;
    } 
    else if (child_pid == 0) 
    {
        grandchild1_pid = fork(); 

        if (grandchild1_pid == -1) 
        {
            printf("Failed to create first grandchild process.\n");
            return 1;
        } 
        else if (grandchild1_pid == 0) 
            printf("First grandchild PID: %d\n", getpid());
        else 
        {
            grandchild2_pid = fork(); 
            if (grandchild2_pid == -1) 
            {
                printf("Failed to create second grandchild process.\n");
                return 1;
            } 
            else if (grandchild2_pid == 0) 
                printf("Second grandchild PID: %d\n", getpid());
            else 
            {
                grandchild3_pid = fork(); 
                if (grandchild3_pid == -1) 
                {
                    printf("Failed to create third grandchild process.\n");
                    return 1;
                } 
                else if (grandchild3_pid == 0) 
                    printf("Third grandchild PID: %d\n", getpid());
            }
        }
    } 
    else 
    {
        wait(NULL); 
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}