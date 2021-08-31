#include <stdio.h>

int main(int argc, char *argv[]) {
        int height;
        sscanf(argv[1],"%d",&height);
        for(int i=0;i<height;i++){
                int stars = (2*(i+1))-1;
                int spaces = 2*height-stars;
                for(int j=0;j<spaces/2;j++){
                        printf(" ");
                }
                for(int j=0;j<stars;j++){
                        printf("*");
                }
                printf("\n");
        }
        return 0;
}


