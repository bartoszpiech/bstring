#include <stdio.h>
#include "bstring.h"

int main() {
	bstring my_string = bstring_new("MUO-");
	bstring_mul(my_string, 10);
	bstring_print(my_string);
	bstring_delete(my_string);
}
