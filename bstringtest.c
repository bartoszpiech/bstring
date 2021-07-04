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
	bstring my_string = bstring_new("ssiemanko");
	printf("[%d]", my_string->len);
	bstring my_string2 = bstring_new("elo");
	printf("[%d]", my_string2->len);
	bstring sum = bstring_cat(my_string, my_string2);
	//printf("[%d]", sum->len);
	//printf("%d\n%s\n", bstring_count(my_string, 's'), my_string->data);
	//bstring_print(sum);
	bstring_delete(sum);
	bstring_delete(my_string);
	bstring_delete(my_string2);
}
