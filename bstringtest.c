#include <stdio.h>
#include "bstring.h"
#include "../blist/blist.h"

blist_t *bstring_split(bstring_t *str, const char *divider) {
	int div_len = 0;
	while (divider[div_len] != 0) {
		div_len++;
	}
	blist_t *list = blist_new();
	bstring_t *helper = bstring_copyb(str);
	for (int div_index = bstring_find(helper, divider);
			div_index != -1;
			div_index = bstring_find(helper, divider)) {
		bstring_t *part = bstring_copyb(helper);
		bstring_slice(part, 0, div_index);
		blist_append(list, part);
		bstring_slice(helper, div_index+div_len, -1);
	}
	blist_append(list, helper);
	return list;
}
int main() {
	bstring_t *my_string = bstring_new("raz\ndwa\ntrzy", 12);
	bstring_print(my_string);
	bstring_print(my_string);
	blist_t *list = bstring_split(my_string, "\n");
	blist_foreach(list) {
		bstring_print((bstring_t*)iterator->value);
	}
	blist_foreach(list) {
		bstring_delete((bstring_t*)iterator->value);
	}
	bstring_delete(my_string);
	blist_delete(list);
}
