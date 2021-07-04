#include <stdio.h>
#include <stdlib.h>

#include "bstring.h"
/* OK */
/* malloc free strlen memcpy snprintf */

/* NOT OK */
/* strcpy strncpy strcat strncat */

int bstring_init(bstring str, const char *text) {
	str->size = 0;
	for (int i = 0; text[i] != 0; i++) {
		str->size++;
	}
	if ((str->data = malloc(str->size)) == NULL) {
		fprintf(stderr, "Error: could not allocate space for bstring\n");
		exit(1);
	}
	for (int i = 0; i < str->size; i++) {
		str->data[i] = text[i];
	}
	return 0;
}
bstring_t bstring_new(const char *text) {
	bstring str;
	if ((str = malloc(sizeof(bstring_t))) == NULL) {
		fprintf(stderr, "Error: could not allocate space for bstring\n");
		exit(1);
	}
	bstring_init(str, text);
	return str;
}

void bstring_destroy(bstring str) {
	free(str->data);
}

void bstring_delete(bstring str) {
	bstring_destroy(str);
	free(str);
}
