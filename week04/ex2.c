#include <stdio.h>
#include <unistd.h>

int main() {

   for(int i = 0; i < 3; i++){
       fork();
       sleep(5);
   }

}
