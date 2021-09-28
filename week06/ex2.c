#include "stdio.h"
#include "stdlib.h"

typedef struct row {
    int Bt;
    int At;
} fileRow;

typedef struct csvFile {
    fileRow *row;
    int size;
} csvFile;

csvFile *parseFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("CSV file does not exist !!");
        exit(1);
    }
    int size = 0;
    for (char c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            size++;
        }
    }

    freopen(fileName, "r", file);
    fileRow *row = malloc(size * sizeof(fileRow));
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d,%d", &row[i].At, &row[i].Bt);
    }
    fclose(file);
    csvFile *csvFile = malloc(sizeof(csvFile));
    csvFile->row = row;
    csvFile->size = size;
    return csvFile;
}

void swap(int *arrival1, int *burst1, int *arrival2, int *burst2) {
    int arrivalTmp = *arrival1;
    int burstTmp = *burst1;
    *arrival1 = *arrival2;
    *burst1 = *burst2;
    *arrival2 = arrivalTmp;
    *burst2 = burstTmp;
}

int main() {
    csvFile *csvFile = parseFile("new_input.csv");

    int n = csvFile->size;
    int AT[n], BT[n], CT[n], TAT[n], WT[n];
    float averageTAT = 0;
    float averageWT = 0;
    for (int i = 0; i < n; i++) {
        AT[i] = csvFile->row[i].At;
        BT[i] = csvFile->row[i].Bt;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (AT[j] > AT[j+1]) {
                swap(&AT[j], &BT[j], &AT[j+1], &BT[j+1]);
            } else if (AT[j] == AT[j+1]) {
                if (BT[j] > BT[j+1]) {
                    swap(&AT[j], &BT[j], &AT[j+1], &BT[j+1]);
                }
            }
        }
    }


    WT[0] = 0;
    TAT[0] = BT[0];

    for (int i = 0; i < n; i++) {
        CT[i] = AT[i] + TAT[i];
        if (i + 1 < n) {
            if (CT[i] > AT[i + 1]) {
                WT[i + 1] = CT[i] - AT[i + 1];
            } else {
                WT[i + 1] = 0;
            }
            TAT[i + 1] = BT[i + 1] + WT[i + 1];
        }

    }
    for (int (i) = 0; (i) < n; ++(i)) {
        averageTAT += TAT[i];
        averageWT += WT[i];
    }

    averageTAT = averageTAT / n;
    averageWT = averageWT / n;

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Turnaround Time = %f\n", averageTAT);
    printf("Average WT = %f\n", averageWT);
    free(csvFile->row);
    free(csvFile);
}
