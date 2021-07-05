#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bstring.h"

int main() {
	bstring_t *my_string = bstring_new("MUO-", 4);
	bstring_mul(my_string, 50);
	printf("%d, %.*s\n", my_string->len, my_string->len, my_string->data);
	bstring_print(my_string);
	bstring_delete(my_string);
}
