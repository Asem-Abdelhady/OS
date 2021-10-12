#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    for (int i = 0; i < 15; i++) {
        size_t size = 10 * 1024 * 1024;
        int *ptr = malloc(size);
        memset(ptr,0,size);
        sleep(1);
        //the fields remain 0 for the vmstat 1
	//the memory field for top -p PID keeps increasing every second
    }
}



