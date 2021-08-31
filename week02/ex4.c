#include <stdio.h>

void swap(int *firstNumber,int *secondNumber){
        int temp;
        temp=*firstNumber;
        *firstNumber=*secondNumber;
        *secondNumber=temp;
}

int main() {
        int firstNumber,secondNumber;
        scanf("%d",&firstNumber);
        scanf("%d",&secondNumber);
        swap(&firstNumber,&secondNumber);
        printf("%d %d\n",firstNumber,secondNumber);
        return 0;
}







