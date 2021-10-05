#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void* new_realloc(void* ptr, int old_size, int new_size){
    if(ptr == NULL){
        return malloc(new_size);
    }

    else if(new_size == 0){
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);
    size_t min;
    if(new_size > old_size){
        min = old_size;
    }
    else{
        min = new_size;
    }

    memcpy(new_ptr,ptr,min);

    free(ptr);
    return new_ptr;
}


int main(){
    //Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size: ");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = malloc(n1*sizeof (int));
    int i;
    for(i=0; i<n1; i++){
        a1[i] = 100;
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i] );
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    a1 = new_realloc(a1,n1*sizeof(int),n2*sizeof(int));

    size_t n = sizeof (a1);


    for(int j = 0; j < n2; j++){
        printf("%d ", a1[j]);
    }

    printf("\n");

    return 0;
}
