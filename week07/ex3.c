#include <stdlib.h>
#include <stdio.h>
#include <time.h>


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
    a1 = realloc(a1, n2);

    if(n2 > n1){
        for(int j = n1; j < n2; j++){
            a1[j]  = 0;
        }
    }


    for(i=0; i<n2;i++){
        printf("%d ",a1[i]);
    }
    printf("\n");

    return 0;
}
