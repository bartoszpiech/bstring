#include <stdio.h>
#include <math.h>
#include "bstring.h"

void print_f(float a) {
	printf("%f\n", a);
}
void print_i(int a) {
	printf("%d\n", a);
}
void print_s(char *a) {
	printf("%s\n", a);
}

#define print(A)		\
	_Generic ((A),		\
		double: print_f,	\
		int: print_i,	\
		char *: print_s)(A)\

#define fabs(X) \
	_Generic((X), \
			float: fabsf, \
			long double: fabsl, \
			default: fabs)(X)

int main() {
	bstring_t my_string = bstring_new("siemanko");
	printf("%d\n", my_string->size);
	bstring_delete(my_string);
	//printf("%d\n", my_string == NULL ? 1 : 0);
	/*
	bstring_t my_string = bstring("siema");
	printf("[%s;%d]\n", my_string->data, my_string->size);
	bstring_free(my_string);
	*/
}
