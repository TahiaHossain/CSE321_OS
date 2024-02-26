#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        execvp("./sort", argv);
        printf("Exec failed\n");
        return 1;
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to finish

        printf("Parent process printing odd/even status:\n");
        execvp("./odeven", argv);
        printf("Exec failed\n");
        return 1;
    }

    return 0;
}