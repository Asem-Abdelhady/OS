#include <stdio.h>

int main(void) {
	char str[256];
	printf("Enter the string: ");
	fgets(str,256,stdin);
	
	int n = strlen(str);
	for(int i = n-1; i >= 0; i--){
		printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}
