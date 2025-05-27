#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork(); // Create a child process

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process
        printf("Child process:\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent child PID: %d\n", pid);
        wait(NULL);              // Wait for child to finish
        waitpid(pid, NULL, 0);   // Optionally wait for specific child
        printf("Parent process terminates\n");
    }

    return 0;
}
