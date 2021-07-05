#include <stdio.h>
#include "bstring.h"

int main() {
	bstring_t *my_string = bstring_new("raz dwa trzy dwa", 17);
	bstring_print(my_string);
	bstring_replace(my_string, "dwa", "siedem");
	bstring_replace(my_string, "dwa", "siedem");
	bstring_print(my_string);
	bstring_delete(my_string);
}
