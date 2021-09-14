#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1000

int main() {

    char commandLine[100000];
    char *commandArguments[100000];


    printf("Enter you command >>> ");
    while (1) {
        for (int i = 0; i < MAX_SIZE; i++) {
            commandLine[i] = '\0';
            commandArguments[i] = NULL;
        }


        fgets(commandLine, sizeof(commandLine), stdin);

        int w = 0;
        int c = 0;

        commandArguments[0] = (char *) malloc(MAX_SIZE);
        for (int i = 0; i < strlen(commandLine) - 1; i++) {
            if (commandLine[i] == ' ') {
                commandArguments[w++][c] = '\0';
                commandArguments[w] = (char *) malloc(MAX_SIZE);
                c = 0;
            } else {
                commandArguments[w][c++] = commandLine[i];
            }
        }

        int n = fork();
        if (n == 0) {
            execvp(commandArguments[0], commandArguments);
        }
    }
}
