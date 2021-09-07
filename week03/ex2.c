#include <stdio.h>
#define ARR_SIZE(x) (sizeof(x)/sizeof((x)[0]))
void swap (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(int arr[], int arr_len){
	for(int i = 0; i < arr_len; i++){
		for(int j = 0; j < arr_len - i -1; j++){
			if(arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
		}
	}
}




void print_array(int arr[], int arr_size){
	for(int i =0; i < arr_size; i++){
		printf("%d\n", arr[i]);
	}
}
int main(void) {
	int arr[] = {3,7,4,1,2,6,5};
	printf("The initial array is:\n");
	int length = ARR_SIZE(arr);
	print_array(arr, length);
	bubble_sort(arr, length);
	printf("Array after bubble sort:\n");
	print_array(arr,length);
	return 0;
}
