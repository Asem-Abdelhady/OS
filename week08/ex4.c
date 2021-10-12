#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    printf("Memory usage\tru_ixress\tru_idress\tru_isress\n");
    struct rusage usage;
    for (int i = 0; i < 9; i++) {
        getrusage(RUSAGE_SELF, &usage);
        int *ptr = malloc(10*1024*1024);
        memset(ptr, 0, sizeof(&ptr));
        printf("            \t%ld\t%ld\t%ld\n", usage.ru_ixrss,usage.ru_idrss,usage.ru_isrss);
        sleep(1);
    }
}
