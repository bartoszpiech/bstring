#include <stdio.h>
#include "bstring.h"

int main() {
	bstring_t *my_string = bstring_new("hello world", 11);
	bstring_print(my_string);
	bstring_slice(my_string, 2, 8);
	bstring_print(my_string);
	bstring_delete(my_string);
}
