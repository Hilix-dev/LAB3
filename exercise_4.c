#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t vim_pid;

void on_sigint(int sig) {
    kill(vim_pid, SIGKILL);
    waitpid(vim_pid, NULL, 0);
    printf("\nYou are pressed CTRL+C! Goodbye!\n");
    exit(0);
}

int main() {
    printf("Welcome to IT007, I am <your_Student_ID>!\n");

    vim_pid = fork();
    if (vim_pid == 0) {
        // Tách tiến trình con ra khỏi process group của cha
        setpgrp();
        execl("/usr/bin/vim", "vim", "abcd.txt", NULL);
        exit(1);
    }

    signal(SIGINT, on_sigint);
    wait(NULL);

    return 0;
}
