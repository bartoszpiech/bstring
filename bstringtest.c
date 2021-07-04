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

int main() {
	bstring my_string = bstring_new("siemankoss");
	bstring my_string2 = bstring_new("elos");
	my_string = bstring_cat(my_string, my_string2);
	printf("%d\n%s\n", bstring_count(my_string, 's'), my_string->data);
	printf("%s", my_string2->data);
	bstring_delete(my_string);
	bstring_delete(my_string2);
}
