#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

int main(void) {
	int i = INT_MAX;
	double d = DBL_MAX;
	float f = FLT_MAX;
	
	printf("This is the max integer value: %d\n", i);
	printf("This is the max double value: %lf\n", d);
	printf("This is the max float value: %f\n", f);
	printf("This is the size of integer: %d\n",sizeof(i));
	printf ("This is the size of float: %d\n", sizeof(f));
	printf("This is the size of double: %d\n", sizeof(d));
	return 0;
}
