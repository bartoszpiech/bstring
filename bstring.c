#include <stdlib.h>

#include "bstring.h"
/* OK */
/* malloc free strlen memcpy snprintf */

/* NOT OK */
/* strcpy strncpy strcat strncat */

bstring_t bstring(const char *text) {
	bstring_t result = malloc(sizeof(bstring_t));
	result->size = 0;
	for (int i = 0; text[i] != 0; i++) {
		result->size++;
	}
	result->data = malloc(result->size);
	for (int i = 0; i < result->size; i++) {
		result->data[i] = text[i];
	}
	return result;
}

void bstring_free(bstring_t str) {
	free(str->data);
	free(str);
}
