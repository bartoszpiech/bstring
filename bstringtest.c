#include <stdio.h>
#include <stdlib.h>
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

void bstring_print(bstring str) {
	printf("%.*s\n", str->len, str->data);
}

int main() {
	bstring my_string = bstring_new("MUO-");
	bstring_mul(my_string, 5);
	bstring_print(my_string);
	bstring_delete(my_string);
}
