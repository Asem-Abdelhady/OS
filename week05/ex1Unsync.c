#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void printMessage(void *i) {
    printf("terminating thread %d\n", *(int *) i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    char *end;
    const long n = strtol(argv[1], &end, 10);
    void *fp = &printMessage;
    for (int i = 1; i <= n; i++) {
        pthread_t pthread;
        printf("creating thread %d\n", i);
        pthread_create(&pthread, NULL, fp, (void *) &i);
    }
}

