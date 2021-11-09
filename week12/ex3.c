#include <stdio.h>
#include <dirent.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = 0;
    }
    FILE *charactersPressed = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    struct input_event inputChar;


    while (1) {

        fread(&inputChar, sizeof(struct input_event), 1, charactersPressed);
        if (inputChar.type != EV_KEY) continue;

        a[inputChar.code] = inputChar.value;

        if (a[25] == 2 && a[18] == 2 || a[25] == 1 && a[18] == 1) {
            printf("I passed the Exam\n");
        }
        if (a[46] == 2 && a[30] == 2 && a[25] == 2 || a[46] == 1 && a[30] == 1 && a[25] == 1) {
            printf("Get some cappuccino!\n");
        }

        if (a[46] == 2 && a[18] == 2 || a[46] == 1 && a[18] == 1) {
            printf("El3os yor7b\n");
        }
    }
}

