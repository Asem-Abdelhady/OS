#include <stdio.h>
#include <unistd.h>

int main() {

    int n = fork();

    if(n == 0){
        printf("Hello from child [%d, %d]\n", getpid(), n);
    }

    else if (n > 0){
        printf("Hello from parent [%d, %d]\n", getpid(), n);
    }

    else{
        printf("Unable to creat process");
    }

}
