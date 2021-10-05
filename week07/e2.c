#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    int* arr = malloc(N*sizeof(int));
    int i = 0;
    while ( i < N){
        arr[i] = i;
        i++;
    }

    int j = 0;
    while(j < N){
        printf("Array's %d number:  %d\n",j, arr[j]);
        j++;
    }

    free(arr);
    return 0;
}
