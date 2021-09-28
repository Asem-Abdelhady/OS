#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
# define SIZE 10

int queue[SIZE];
int Rear = - 1;
int Front = - 1;
int emp=0;

void enqueue(int process)
{
    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else
    {
        if (Front == - 1)
            Front = 0;
        Rear = Rear + 1;
        queue[Rear] = process;
    }
}

void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        Front = Front + 1;
    }
}

void show()
{

    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

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
    for (char c = getc(file); c != EOF; c = getc(file)){
        if (c == '\n'){
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

void swap(int *At1, int*Bt1, int *At2, int *Bt2){
    int AtTmp = *At1;
    int BtTmp = *Bt1;
    *At1 = *At2;
    *Bt1 = *Bt2;
    *At2 = AtTmp;
    *Bt2 = BtTmp;
}

int main(int argc, char* argv[]) {
      char *end;
      const long quantumTime = strtol(argv[1], &end, 10);
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
                if (BT[j] < BT[j+1]) {
                    swap(&AT[j], &BT[j], &AT[j+1], &BT[j+1]);
                }
            }
        }
    }

    int bt[n];

    for(int i = 0; i < n; i++){
        bt[i]=BT[i];
    }


    int temp = quantumTime;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < n; j++) {
            if (AT[j] == i) {
                enqueue(j);
                emp++;
            }
        }
        if(temp==0){
            temp=quantumTime;
        }
        temp--;
        if (emp!=0) {
            bt[queue[Front]]--;
            if (bt[queue[Front]] == 0) {
                CT[queue[Front]] = i+1;
                dequeue();
                emp--;
            }
            else if (temp == 0) {
                int tmpp=queue[Front];
                dequeue();
                emp--;
                if (bt[tmpp] != 0) {
                    enqueue(tmpp);
                    emp++;
                }
            }
        }


    }

    for(int i = 0; i < n; i++){
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
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
