#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild_pid;

    child_pid = fork(); 

    if (child_pid < 0) 
    {
        printf("Error creating child process\n");
        return 1;
    } 
    else if (child_pid == 0) 
    {
        grandchild_pid = fork(); 

        if (grandchild_pid < 0) 
        {
            printf("Error creating grandchild process\n");
            return 1;
        } 
        else if (grandchild_pid == 0) 
            printf("I am grandchild\n");
        else 
        {
            wait(NULL); 
            printf("I am child\n");
        }
    } 
    else 
    {
        wait(NULL); 
        printf("I am parent\n");
    }

    return 0;
}