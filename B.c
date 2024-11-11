Q.2) Write a C program that catches the ctrl-c (SIGINT) signal for the first time and display the appropriate message and exits on pressing ctrl-c again.

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int sigint_count = 0;

void sigint_handler(int sig) {
    sigint_count++;
    if (sigint_count == 1) {
        printf("Ctrl-C pressed! Press again to exit.\n");
    } else {
        printf("Exiting on second Ctrl-C press.\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        // Infinite loop to keep the program running
    }

    return 0;
}

Output:

Ctrl-C pressed! Press again to exit.

(After second Ctrl-C)
Exiting on second Ctrl-C press.

