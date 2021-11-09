#include <stdio.h>
#include <linux/input.h>
int main() {
    FILE* charactersPressed = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    FILE* ex2 = fopen("ex2.txt", "w");
    struct input_event inputChar;
    while (1) {
        fread(&inputChar, sizeof(struct input_event), 1,  charactersPressed);
        if (inputChar.type != EV_KEY) continue;
        if (inputChar.value	== 0) {
            printf("RELEASED %#x (%d)\n", inputChar.code, inputChar.code);
            fprintf(ex2, " RELEASED %#x (%d)\n", inputChar.code, inputChar.code);
        } else if (inputChar.value == 1) {
            printf(" PRESSED %#x (%d)\n", inputChar.code, inputChar.code);
            fprintf(ex2, " PRESSED %#x (%d)\n", inputChar.code, inputChar.code);
        }
    }
}
