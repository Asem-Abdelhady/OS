#include <stdio.h>
#include <stdlib.h>

int main()
{
    char userCommand[1000];
    int n = 1;
    while(n){
        printf("Enter your command: \n>>> ");
        scanf("%s", userCommand);
        system(userCommand);
    }
   

}

